class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vis;
    vector<long long> dp;
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        graph.resize(n);
        vis.resize(n,0);
        dp.resize(n,-1);

        vector<int> deg(n,0);
        for(auto x: edges){
            int u = x[0], v = x[1];
            graph[u].push_back(v); 
            graph[v].push_back(u); 
            deg[u]++, deg[v]++;
        }
        
        long long totValues = values[0];
        for(int i = 1; i < n; i++){
            if(deg[i] == 1)dp[i] = values[i];
            totValues += values[i];
        }

        vis[0] = 1;
        return totValues - dfs(0, values);
        
    }

    long long dfs(int node, vector<int>& values){
        if(dp[node] != -1)return dp[node];

        long long totLoss = 0;
        for(auto nbr: graph[node]){
            if(vis[nbr] == 0){
                vis[nbr] = 1;
                dp[nbr] = dfs(nbr,values);
                totLoss += dp[nbr];
            }
        }

        return dp[node] = min(1LL*values[node], totLoss);
    }
};