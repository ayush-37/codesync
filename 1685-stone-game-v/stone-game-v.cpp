class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n+1,0);
        for(int i = 1; i <= n; i++)pref[i] = pref[i-1] + stoneValue[i-1];
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,pref,dp);
    }
    int solve(int l, int r, vector<int>& pref, vector<vector<int>>& dp){
        if(l == r)return 0;
        if(dp[l][r] != -1)return dp[l][r];

        int ans = 0;
        for(int k = l; k <= r-1; k++){
            int left = pref[k]-pref[l-1];
            int right = pref[r]-pref[k];
            if(left < right){
                ans = max(ans, left + solve(l,k,pref,dp));
            }
            else if(left > right){
                ans = max(ans, right + solve(k+1,r,pref,dp));
            }
            else {
                ans = max(ans, left + solve(l,k,pref,dp));
                ans = max(ans, right + solve(k+1,r,pref,dp));
            }
        }

        return dp[l][r] = ans;
    }
};

//   6 2  3  4  5  5
// 0 6 8 11 15 20 25