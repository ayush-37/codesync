class Solution {
public:
    using ll = long long;
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m = requests.size();
        int sz = 1 << m;

        vector<vector<ll>> dp(sz,vector<ll>(m,LLONG_MAX));
        // base case , i go to floor 'floor' at index i from start position
        for(int i = 0; i < m; i++){
            ll time = requests[i][0];
            ll floor = requests[i][1];

            ll msk = 1 << i;
            dp[msk][i] = max(time, abs(floor - (ll)start));
        }
        
        // DP transition
        for(ll msk = 1; msk < sz; msk++){
            for(int j = 0; j < m; j++){
                if (!(msk & (1 << j)))continue;

                if(dp[msk][j] == LLONG_MAX)continue;
            
                ll currTime = dp[msk][j];

                for(int k = 0; k < m; k++){
                    if(msk & (1<<k))continue;

                    ll time = requests[k][0];
                    ll floor = requests[k][1];

                    ll reachTime = currTime + abs((ll)requests[j][1] - floor);
                    ll newTime = max(reachTime, time);

                    ll newMsk = msk | (1<<k);

                    dp[newMsk][k] = min(dp[newMsk][k], newTime);
                }
            }
        }

        ll ans  = LLONG_MAX;
        for(int i = 0; i < m; i++)ans = min(ans,dp[sz-1][i]);
        return ans;
    }
};