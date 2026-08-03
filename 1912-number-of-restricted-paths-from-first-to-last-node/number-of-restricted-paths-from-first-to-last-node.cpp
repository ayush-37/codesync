class Solution {
public:
    const int MOD = 1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto x: edges){
            int u = x[0];
            int v = x[1];
            int w = x[2];

            graph[v].push_back({u,w});
            graph[u].push_back({v,w});
        }

        dist[n] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,n});

        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            
            if(dis > dist[node]) continue;

            for(auto [nbr,wt] : graph[node]){
                if(dis + wt < dist[nbr]){
                    dist[nbr] = dis+wt;
                    pq.push({dist[nbr], nbr});    
                }
            }
        }

        vector<int> way(n+1,-1);
        int ans = dfs(1,graph,dist,way);
        return ans;

    }

    int dfs(int u, vector<vector<pair<int,int>>>& graph, vector<int>& dist, vector<int>& way){
        if(u == (int)dist.size()-1)return 1;
        if(way[u] != -1)return way[u];

        long long paths = 0;
        for(auto [v,wt] : graph[u]){
            if(dist[v] < dist[u]){
                paths = (paths + dfs(v,graph,dist,way)) % MOD;
            }
        }
        return way[u] = paths;
    }
};