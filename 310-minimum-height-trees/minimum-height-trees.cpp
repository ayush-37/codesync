class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)return {0};
        
        vector<vector<int>> graph(n);
        for(auto x: edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        auto bfs = [&](int start){
            vector<int> par(n,-1);
            vector<int> dis(n,-1);
            int farthest = start;

            queue<int> q;
            q.push(start);
            dis[start] = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto nbr: graph[node]){
                    if(dis[nbr] != -1)continue;

                    dis[nbr] = dis[node]+1;
                    par[nbr] = node;
                    if(dis[nbr] > dis[farthest])farthest = nbr;
                    q.push(nbr);
                }
            }

            return pair<int,vector<int>> (farthest, par);
        };

        auto [firstLeaf,parent1] = bfs(0);
        auto [secondLeaf,parent2] = bfs(firstLeaf);

        vector<int> dia;
        int curr = secondLeaf;
        while(curr != -1){
            cout<<curr<<" ";
            dia.push_back(curr);
            curr = parent2[curr];
        }

        int s = dia.size();
        if(s % 2 == 1)return {dia[s/2]};
        else return {dia[s/2 - 1],dia[s/2]};
    }
};