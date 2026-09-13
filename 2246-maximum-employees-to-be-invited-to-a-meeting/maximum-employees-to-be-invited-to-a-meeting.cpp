class Solution {
/*
1. Build functional graph + reverse graph
                ↓
2. DFS
                ↓
       Find maximum cycle
       Find all 2-cycles
                ↓
3. For every 2-cycle
                ↓
   Find longest incoming chain
   on both sides using reverse BFS
                ↓
4. max(
       longest cycle,
       sum of all 2-cycles + chains
   )


*/
public:
    vector<vector<int>> graph, revGraph;
    vector<int> vis;
    vector<pair<int,int>> perfectCouple;
    int n, maxiCyc;
    int maximumInvitations(vector<int>& favorite) {
        n = favorite.size();
        graph.clear(), revGraph.clear();
        graph.resize(n), revGraph.resize(n);

        for(int i = 0; i < n; i++){
            graph[i].push_back(favorite[i]);
            revGraph[favorite[i]].push_back(i);
        }
        vis.assign(n,0);
        maxiCyc = 0;
        vector<int> curr(n,0);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                dfs(i,curr,0);
            }
        }

        int cnt = 0;
        for(auto [n1, n2] : perfectCouple){
            int len1 = 0, len2 = 0;
            len1 = bfs(n1, n2);
            len2 = bfs(n2, n1);

            cnt += len1 + len2 + 2;
        }

        return max(cnt, maxiCyc);
    }

    int bfs(int n1, int n2){
        vector<int> vis(n,0);
        queue<int> q;
        q.push(n1);
        vis[n1] = 1, vis[n2] = 1;
        int lev = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                for(auto nbr: revGraph[node]){
                    if(vis[nbr] == 0){
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
            lev++;
        }
        return lev-1;
    }

    void dfs(int node, vector<int>& curr, int back){
        back++;
        vis[node] = 1;
        curr[node] = back;

        for(auto nbr: graph[node]){
            if(vis[nbr] == 0){
                dfs(nbr, curr, back);
            }
            else{
                if(curr[nbr] != 0){
                    maxiCyc = max(maxiCyc, curr[node] - curr[nbr] + 1);
                    if(curr[node] - curr[nbr] + 1 == 2){
                        perfectCouple.push_back({node, nbr});
                    }
                }
            }
        }

        curr[node] = 0;
    }
};