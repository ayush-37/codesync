class Solution {
public:
    const int MOD = 1e9+7;  
    vector<vector<int>> memo;   
    int numberOfSets(int n, int k) {
        memo.resize(n+1,vector<int>(k+1,-1));
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
        int take = 0;
        int i = n-1;
        while(i >= 2){
            take = (take + solve(i,k-1)) % MOD;
            i--;
        }

        memo[n][k] = (take + notTake) % MOD;
        return memo[n][k];
    }
};