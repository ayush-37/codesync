class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> memo, suffix;
    int numberOfSets(int n, int k) {
        memo.resize(n+1, vector<int>(k+1,-1));
        suffix.assign(n + 1, vector<int>(k + 1, -1));
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
        take = getSuffix(i + 1, n, k - 1);
        skip = solve(i+1, n, k);

        return memo[i][k] = (take + skip) % MOD;
    }

    int getSuffix(int i, int n, int k) {

        if(i >= n)
            return 0;

        if(suffix[i][k] != -1)
            return suffix[i][k];

        int current = solve(i, n, k);
        int remaining = getSuffix(i + 1, n, k);

        return suffix[i][k] = (current + remaining) % MOD;
    }
};