class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,set<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].insert(i);
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int temp = nums[i];
            int sum = 0;
            while(temp){
                int r = temp%10;
                sum *= 10;
                sum += r;
                temp/=10;
            }

            if(mp.count(sum)){
                auto itr = mp[sum].upper_bound(i);
                if(itr != mp[sum].end())ans = min(ans,abs(i - *itr));
            }
        }
        if(ans == INT_MAX)return -1;
        else return ans;
    }
};