class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = LLONG_MAX;

        multiset<long long> small, large;
        long long sumSmall = 0;
        int need = k - 2;

        auto add = [&](long long x){
            if(small.size() < need){
                small.insert(x);
                sumSmall += x;
            } else {
                if(need && x < *prev(small.end())){
                    long long y = *prev(small.end());
                    small.erase(prev(small.end()));
                    sumSmall -= y;
                    large.insert(y);

                    small.insert(x);
                    sumSmall += x;
                } else {
                    large.insert(x);
                }
            }
        };

        auto remove = [&](long long x){
            if(small.find(x) != small.end()){
                small.erase(small.find(x));
                sumSmall -= x;
            } else {
                large.erase(large.find(x));
            }

            if(small.size() < need && !large.empty()){
                long long y = *large.begin();
                large.erase(large.begin());
                small.insert(y);
                sumSmall += y;
            }
        };

        // initialize first window for i = 1
        for(int j = 2; j <= 1 + dist; j++)
            add(nums[j]);

        for(int i = 1; i < n - need; i++){
            long long cur = nums[0] + nums[i] + sumSmall;
            ans = min(ans, cur);

            // slide window
            if(i + dist + 1 < n)
                add(nums[i + dist + 1]);

            remove(nums[i + 1]);
        }

        return ans;
    }
};