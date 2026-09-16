class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    int numberOfSets(int n, int k) {
        memo.resize(n+1, vector<int>(k+1,-1));
        return solve(0,n,k);
    }
    int solve(int i, int n, int k){
        if(k == 0)
        return 1;

        if(i == n)
            return 0;

        if(n - i < k + 1)
        return 0;

        if(memo[i][k] != -1)return memo[i][k];

        int take = 0, skip = 0;
        for(int j = i+1; j < n; j++){
            take = (take + solve(j,n,k-1)) % MOD;
        }
        skip = solve(i+1, n, k);

        return memo[i][k] = (take + skip) % MOD;
    }
};