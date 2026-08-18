class Solution {
public:
    using ll = long long;
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<ll>> dp(n,vector<ll>(n,-1));
        return solve(0,n-1,arr,dp);
    }
    ll solve(int l, int r, vector<int>& arr, vector<vector<ll>>& dp){
        if(l == r)return 0;
        if(dp[l][r] != -1)return dp[l][r];

        ll lm = 0, ans = LLONG_MAX;
        for(int i = l; i < r; i++){
            lm = max(lm,arr[i]*1LL);
            ll rm = 0;
            for(int j = i+1; j <= r; j++)rm = max(rm, arr[j]*1LL);

            ans = min(ans, lm*rm + solve(l,i,arr,dp) + solve(i+1,r,arr,dp));
        }
        return dp[l][r] = ans;
    }
};