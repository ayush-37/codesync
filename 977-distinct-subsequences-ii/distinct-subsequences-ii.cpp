class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        const int MOD = 1e9+7;
        vector<int> dp(n+1,0);
        vector<int> prev(26,-1);
        for(int i = 1; i <= n; i++){
            dp[i] = (2*dp[i-1] + 1) % MOD; // dp[i] = dp[i-1](seq till i-1) + dp[i-1](new seq on appending s[i-1] with seq till i-1) + 1(s[i-1])

            char c = s[i-1];
            // if the character is already present then all the seq ending with s[i-1] will become duplicate so we have to subtract it 
            if(prev[c - 'a'] != -1)dp[i] = (dp[i] - (dp[prev[c-'a'] -1]+1) + MOD)%MOD;
            // (dp[prev[c-'a'] -1]+1) represents total number of subsequences before the previous index -> all the distinct seq before j = prev[c-'a'] and 1 empty seq
            prev[c-'a'] = i;
        }

        return dp[n];
    }
};