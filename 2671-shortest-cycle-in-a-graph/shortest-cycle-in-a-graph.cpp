class Solution {
public:
/*
    if only cycle detection is asked then dfs itself if sufficient 
    but since shortest path is asked we should use bfs as it covers one level at a time 
    so our idea is we will go through every node as source and find distance of every node from that source 
    if we encounter any nbr node which is already visited then we have found a cycle 
    such that 
            source ------- node
              ||              |    in this cycle length would be dist source to node + dist source to nbr + 1
            source --------nbr

*/
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph;
        graph.resize(n,{});
        for(auto x: edges){
            int u = x[0], v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            queue<int> q;
            vector<int> dis(n,INT_MAX), par(n,-1);
            q.push(i);
            par[i] = i, dis[i] = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto nbr: graph[node]){
                    if(par[nbr] == -1){
                        par[nbr] = node;
                        dis[nbr] = dis[node]+1;
                        q.push(nbr);
                    }
                    else{
                        if(nbr != par[node]){
                            int len = dis[node] + dis[nbr] + 1;
                            ans = min(ans, len);
                        }
                    }
                }
            }
        }
        return ans == INT_MAX? -1: ans;
    }
};