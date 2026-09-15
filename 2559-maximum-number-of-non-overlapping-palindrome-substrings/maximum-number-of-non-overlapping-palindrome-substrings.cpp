class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1)return n;

        vector<vector<int>> isPal(n+1, vector<int>(n+1,0));
        for(int i = 0; i < n; i++){
            isPal[i][i] = 1;
        }
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    isPal[i][j] = (len == 2? 1: isPal[i+1][j-1]);
                }
            }
        }

        vector<int> dp(n+1,0);
        // dp[i] denote the maximum number of non-overlapping palindromic substrings of length at least k that can be selected from the first i character s[0…i−1].
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1];
            for(int j = 0; j+k <= i; j++){
                if(isPal[j][i-1])dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return dp[n];
    }
};