class Solution {
public:
    const int MOD = 1e9+7;  
    vector<vector<int>> memo, pref;   
    int numberOfSets(int n, int k) {
        memo.resize(n+1,vector<int>(k+1,-1));
        pref.resize(n+1,vector<int>(k+1,-1));
        int ans = solve(n,k);
        return ans;
    }
    int solve(int n, int k){
        if(k == 1){
            return memo[n][k] = ((n * (n-1))%MOD)/2;
        }
        if(n-1 == k)return 1;
        if(n-1 < k)return 0;
        if(memo[n][k] != -1)return memo[n][k];

        int notTake = solve(n-1,k);
        int take = sumPref(n-1,k-1);

        memo[n][k] = (take + notTake) % MOD;
        return memo[n][k];
    }

    int sumPref(int n, int k){
        if(n < 2)return 0;
        if(pref[n][k] != -1)return pref[n][k];
        pref[n][k] = (solve(n,k) + sumPref(n-1,k)) % MOD;
        return pref[n][k];
    }
};