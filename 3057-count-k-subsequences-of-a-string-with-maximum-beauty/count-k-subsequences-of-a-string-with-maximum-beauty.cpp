class Solution {
public:
    using ll = long long;
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int n = s.size();
        const int MOD = 1e9 + 7;
        vector<int> freq(26,0);
        for(auto c: s)freq[c - 'a']++;

        // dp[i][j]:
        // Considering first i characters,
        // choose exactly j characters.
        //
        // beauty = maximum beauty
        // ways   = number of ways to obtain that beauty
        vector<vector<pair<ll,ll>>> dp(27,vector<pair<ll,ll>>(k+1,{-1,0}));

        // Choosing 0 characters has beauty 0
        // and exactly 1 way: choose nothing.
        dp[0][0] = {0,1};

        for(int i = 1; i <= 26; i++){
            int f = freq[i-1];
            for(int j = 0; j <= k; j++){
                dp[i][j] = dp[i-1][j];
                if(j > 0 && dp[i-1][j-1].first != -1){
                    ll nb = dp[i-1][j-1].first + 1LL*f;
                    ll nways = (dp[i-1][j-1].second * 1LL*f) % MOD;
                    if(nb > dp[i][j].first){
                        dp[i][j].first = nb, dp[i][j].second = nways;
                    }
                    else if(nb == dp[i][j].first){
                        dp[i][j].second = (dp[i][j].second + nways) % MOD;;
                    }
                }
            }
        }

        return (int)dp[26][k].second;
    }
};