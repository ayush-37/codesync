class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n+1);
        unordered_map<int,int> mp;
        mp[0] = 0;
        for(int i = 0; i < n; i++){
            presum[i+1] = presum[i] + nums[i];
            if(mp.count(presum[i+1]%k) && ((i+1) - mp[presum[i+1]%k]) >= 2)return true;
            else if(mp.count(presum[i+1]%k) == 0)mp[presum[i+1]%k] = i+1;;
        }

        return false;
    }
};