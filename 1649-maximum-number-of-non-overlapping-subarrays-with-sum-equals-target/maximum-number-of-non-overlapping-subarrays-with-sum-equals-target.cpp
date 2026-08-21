class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int req = sum - target;
            if(mp.count(req)){
                ans++;
                mp.clear();
                mp[0] = 1;
                sum = 0;
            }
            mp[sum] = 1;
        }
        return ans;
    }
};