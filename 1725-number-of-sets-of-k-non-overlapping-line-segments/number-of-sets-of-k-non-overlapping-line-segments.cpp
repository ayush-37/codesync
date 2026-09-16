class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
        for(int i = 0; i < n; i++)dp[0][i] = 1; 

        for(int seg = 1; seg <= k; seg++){
            vector<int> suff(n+1,0);
            for(int i = n-1; i >= 0; i--){
                suff[i] = (suff[i+1] + dp[seg-1][i]) % MOD;
            }
            for(int idx = n-1; idx >= 0; idx--){
                int skip = dp[seg][idx+1];
                int take = suff[idx+1];

                dp[seg][idx] = (take + skip) % MOD;
            }
        }

        return dp[k][0];
    }
};