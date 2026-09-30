class Solution {
public:
    vector<vector<int>> graph, col;
    vector<int> vis;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        graph.assign(n,{});
        col.assign(n,vector<int>(26,0));
        vis.assign(n,0);

        for(auto x: edges){
            int u = x[0], v = x[1];
            graph[u].push_back(v);
        }

        int ans = 0;
        for(int i = 0; i < n && ans != INT_MAX; i++){
            ans = max(ans, dfs(i,colors));
        }
        return ans == INT_MAX? -1: ans;
    }

    int dfs(int node, string& colors){
        if(vis[node] == 0){
            vis[node] = 1;
            for(auto nbr: graph[node]){
                if(dfs(nbr, colors) == INT_MAX)return INT_MAX;
                for(int i = 0; i < 26; i++){
                    col[node][i] = max(col[node][i], col[nbr][i]);
                }
            }

            col[node][colors[node]-'a']+=1;
            vis[node] = 2;
        }
        return vis[node] == 2? col[node][colors[node]-'a']: INT_MAX;

    }

};