class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+2);
        temp[0] = 1, temp[n+1] = 1;
        for(int i = 1; i <= n; i++)temp[i] = nums[i-1];
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int len = 1; len <= n; len++){
            for(int start = 1; start + len - 1 <= n; start++){
                int end = start + len - 1;
                for(int k = start; k <= end; k++){
                    dp[start][end] = max(dp[start][end], temp[start-1] * temp[k] * temp[end+1] + dp[start][k-1] + dp[k+1][end]);
                }
            }
        }
        return dp[1][n];
    }
};