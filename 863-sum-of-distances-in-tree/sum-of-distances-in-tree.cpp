class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vis, dis, child;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto e: edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vis.assign(n,0);
        dis.assign(n,0);
        child.assign(n,0);
        vis[0] = 1;
        pair<int,int> p = dfs(0);

        vis.assign(n,0);
        vector<int> ans(n,0);
        ans[0] = dis[0];
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nbr: graph[node]){
                if(vis[nbr] == 0){
                    vis[nbr] = 1;
                    ans[nbr] = ans[node] - (child[nbr] + 1) + n - (child[nbr] + 1);
                    q.push(nbr);
                }
            }

        }

        return ans;
    }
    pair<int,int> dfs(int node){
        int c = 0, d = 0;
        for(auto nbr: graph[node]){
            if(vis[nbr] == 0){
                vis[nbr] = 1;
                auto [sc,sd] = dfs(nbr);
                c += sc + 1;
                d += (sd + sc + 1);
            }
        }

        child[node] = c, dis[node] = d;
        return {c,d};
    }
};