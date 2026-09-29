class Solution {
public:
    const int MOD = 1e9+7;
    using ll = long long;
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        ll tot = 0;
        for(int i = 1; i <= n; i++){
            ll cnt = find(nums, k, i);
            ll temp = (power(n-i) * cnt)%MOD;
            tot = (tot + temp)%MOD;
        }
        return tot;
    }
    int find(vector<int>& nums, int& t, int k){
        vector<vector<ll>> dp(k+1, vector<ll>(t+1,0));
        dp[0][0] = 1LL;
        for(auto x: nums){
            for(int j = k; j >= 1; j--){
                for(int sum = t; sum >= x; sum--){
                    dp[j][sum] = (dp[j][sum] + dp[j-1][sum-x]) % MOD;
                }
            }
        }

        return dp[k][t];
    }
    ll power(int n){
        ll res = 1, a = 2;
        while(n){
            if(n%2 == 1)res = (res*a)%MOD;
            a = (a*a)%MOD;

            n/=2;
        }
        return res;
    }
};