class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(3, INT_MIN/2)));
        dp[0][1][0] = dp[1][0][0] = 0;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (coins[i - 1][j - 1] >= 0) {
                    dp[i][j][0] = max(dp[i][j - 1][0], dp[i - 1][j][0]) +
                                  coins[i - 1][j - 1];
                    if (dp[i - 1][j][1] != INT_MIN ||
                        dp[i][j - 1][1] != INT_MIN)
                        dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) +
                                      coins[i - 1][j - 1];
                    if (dp[i - 1][j][2] != INT_MIN ||
                        dp[i][j - 1][2] != INT_MIN)
                        dp[i][j][2] = max(dp[i - 1][j][2], dp[i][j - 1][2]) +
                                      coins[i - 1][j - 1];
                } else {
                    dp[i][j][0] = max(dp[i][j - 1][0], dp[i - 1][j][0]) +
                                  coins[i - 1][j - 1];
                    if (dp[i - 1][j][0] != INT_MIN ||
                        dp[i][j - 1][0] != INT_MIN ||
                        dp[i - 1][j][1] != INT_MIN ||
                        dp[i][j - 1][1] != INT_MIN)
                        dp[i][j][1] =
                            max(max(dp[i - 1][j][0], dp[i][j - 1][0]),
                                max(dp[i - 1][j][1], dp[i][j - 1][1]) +
                                    coins[i - 1][j - 1]);
                    if (dp[i - 1][j][1] != INT_MIN ||
                        dp[i][j - 1][1] != INT_MIN ||
                        dp[i - 1][j][2] != INT_MIN ||
                        dp[i][j - 1][2] != INT_MIN)
                        dp[i][j][2] =
                            max(max(dp[i - 1][j][1], dp[i][j - 1][1]),
                                max(dp[i - 1][j][2], dp[i][j - 1][2]) +
                                    coins[i - 1][j - 1]);
                }
            }
        }
        return max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    }
};