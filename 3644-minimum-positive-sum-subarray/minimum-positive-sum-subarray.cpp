class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pref(n+1,0);
        for(int i = 0; i < n; i++)pref[i+1] = pref[i] + nums[i];

        int ans = INT_MAX;
        for(int i = l; i <= r; i++){
            for(int j = i; j <= n; j++){
                if(pref[j]- pref[j-i] <= 0)continue;
                ans = min(ans, pref[j]- pref[j-i]);
            }
        }

        return ans==INT_MAX?-1: ans;
    }
};