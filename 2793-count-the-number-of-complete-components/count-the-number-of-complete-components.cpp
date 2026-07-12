class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                bool is = true;
                int total_nodes = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    if(graph[node].size() != graph[i].size())is = false;
                    for(auto nbr:graph[node]){
                        if(vis[nbr] == 0){
                            total_nodes++;
                            q.push(nbr);
                            vis[nbr] = 1;
                        }
                    }
                }
                if(is && total_nodes-1 == graph[i].size())cnt++;
            }
        }
        return cnt;
    }
};