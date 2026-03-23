class Solution {
public:
    using ll = long long;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int mod = 1e9 + 7;

        vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>> (m,{LLONG_MIN, LLONG_MAX}));
        dp[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0)continue;

                ll maxi = LLONG_MIN, mini = LLONG_MAX;
                ll curr = grid[i][j];

                if(j-1 >= 0){
                    maxi = max({maxi, curr*dp[i][j-1].first, curr*dp[i][j-1].second});
                    mini = min({mini, curr*dp[i][j-1].first, curr*dp[i][j-1].second});
                }

                if(i-1 >= 0){
                    maxi = max({maxi, curr*dp[i-1][j].first, curr*dp[i-1][j].second});
                    mini = min({mini, curr*dp[i-1][j].first, curr*dp[i-1][j].second});
                }

                dp[i][j] = {maxi,mini};
            }
        }

        ll res = dp[n-1][m-1].first;

        if(res < 0)return -1;
        else return (int)(dp[n-1][m-1].first%mod);
    }
};