class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        vector<int> dp(1e6+1,0);
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            // if we include in our ans seq then two possibilities can increase by one and get x+1 which will be appended to x or remain as it is than we get x which will be appended to x-1
            dp[x+1] = max(dp[x+1], dp[x] + 1);  // inc by 1
            dp[x] = max(dp[x], dp[x-1] + 1);    // as it is
            ans = max({ans, dp[x], dp[x+1]});
        }
        return ans;
    }
};