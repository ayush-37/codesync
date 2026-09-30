class Solution {
public:
    using ll = long long;
    const int MOD = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));
        int last = grid[n-1][m-1];
        dp[n-1][m-1][last%k] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int val = grid[i][j];
                if(j+1 < m){
                    for(int x = 0; x < k; x++){
                        if(dp[i][j+1][x] == 0)continue;
                        else{
                            int rem = (val + x)%k;
                            dp[i][j][rem] = (dp[i][j][rem] + dp[i][j+1][x]) % MOD;
                        }
                    }
                }
                if(i+1 < n){
                    for(int x = 0; x < k; x++){
                        if(dp[i+1][j][x] == 0)continue;
                        else{
                            int rem = (val + x)%k;
                            dp[i][j][rem] = (dp[i+1][j][x] + dp[i][j][rem]) % MOD;
                        }
                    }
                }
            }
        }

        return (int)(dp[0][0][0]%MOD);
    }
};