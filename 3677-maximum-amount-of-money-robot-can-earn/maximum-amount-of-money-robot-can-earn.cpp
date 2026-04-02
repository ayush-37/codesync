class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(3,INT_MIN)));
        dp[0][1][0] = dp[1][0][0] = 0;

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                int val = coins[i-1][j-1];
                for(int k = 0; k < 3; k++){
                    int best = max(dp[i-1][j][k],dp[i][j-1][k]);
                    if(best == INT_MIN)continue;

                    dp[i][j][k] = max(dp[i][j][k], best + val);

                    if(val < 0 && k < 2){
                        dp[i][j][k+1] = max(dp[i][j][k+1], best);
                    }
                }
            }
        }

        return max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    }
};

/*
Complexity
Time: O(n * m * 3)
Space: O(n * m * 3)
*/