class Solution {
public:
    int numTrees(int n) {
    vector<int> dp(n+1,0);
    // base case
    dp[0] = 1, dp[1] = 1;
    for(int root = 2; root <= n; root++){
        for(int node = 1; node <= root; node++){
            dp[root] += (dp[node-1] * dp[root-node]);
        }
    }   
    return dp[n];
    }
};