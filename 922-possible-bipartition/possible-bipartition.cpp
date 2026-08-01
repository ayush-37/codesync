class Solution {
public:

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> vis(n+1,0),par(n+1,0);
        vector<vector<int>> graph(n+1);
        for(auto v: dislikes){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        for(int i = 1; i <= n; i++){
            if(vis[i] == 0){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                par[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto nbr: graph[node]){
                        if(vis[nbr] == 0){
                            q.push(nbr);
                            vis[nbr] = 1;
                            par[nbr] = (-1)*par[node];
                        }
                        else{
                            if(par[nbr] == par[node])return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};