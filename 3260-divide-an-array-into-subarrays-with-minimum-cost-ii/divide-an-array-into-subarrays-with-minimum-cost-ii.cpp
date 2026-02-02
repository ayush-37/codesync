class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans = LLONG_MAX;
        int n = nums.size();

        long long size = k-2, sum = 0;

        multiset<long long> large,small;

        auto inst = [&](long long x){
            if(small.size() < size){
                small.insert(x);
                sum += x;
            }
            else{
                if(size && x < *prev(small.end())){
                    long long tx = *prev(small.end());
                    small.erase(prev(small.end()));
                    large.insert(tx);
                    sum -= tx;
                    small.insert(x);
                    sum += x;
                }
                else large.insert(x);
            }
        };

        auto ers = [&](long long x){
            if(small.find(x) != small.end()){
                small.erase(small.find(x));
                sum -= x;
            }
            else{
                large.erase(large.find(x));
            }

            if(small.size() < size && !large.empty()){
                long long tx = *large.begin();
                large.erase(large.begin());
                small.insert(tx);
                sum += tx;
            }
        };

        for(int i = 2; i <= dist+1; i++)inst(nums[i]);

        for(int i = 1; i < n - size; i++){
            ans = min(ans, (long long)(nums[0]+nums[i]+sum));

            if(i+dist+1 < n)inst(nums[i+dist+1]);
            ers(nums[i+1]);
        }

        return ans;
    }
};