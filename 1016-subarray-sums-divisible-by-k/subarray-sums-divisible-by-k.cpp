class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0,ans = 0,rem = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            rem = ((sum%k) + k)%k;
            if(mp.count(rem)){
                ans += mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};