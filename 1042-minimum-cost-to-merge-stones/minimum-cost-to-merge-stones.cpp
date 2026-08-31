class Solution {
public:
/*
3. Base case
for(int i=0;i<n;i++){
    dp[i][i]=0;
}

One stone:

[A]

There is nothing to merge.

Therefore:

dp[A][A] = 0
4. Now the main loop
for(int len=2;len<=n;len++)

We're considering intervals by increasing length.

For example:

len = 2
len = 3
len = 4
len = 5
...

Why?

Because when calculating:

dp[l][r]

we need smaller intervals like:

dp[l][j]
dp[j+1][r]

to already be calculated.

This is the standard interval DP pattern.

*/
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1) != 0)return -1;
        vector<int> pref(n+1,0);
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i] + stones[i];
            dp[i][i] = 0;
        }

        for(int len = 2; len <= n; len++){
            for(int l = 0; l + len - 1 < n; l++){
                int r = l + len - 1;
                for(int s = l; s < r; s += k-1){
                    int curr = dp[l][s]+dp[s+1][r];
                    dp[l][r] = min(dp[l][r],curr);
                }
                if((r-l)%(k-1) == 0)dp[l][r] += pref[r+1] - pref[l];
            }

        }
        return dp[0][n-1];
    }
};