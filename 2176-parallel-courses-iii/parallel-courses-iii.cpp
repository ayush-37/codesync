class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> deg(n,0), timetaken(n,0);
        for(auto x: relations){
            int u = x[0]-1, v = x[1]-1;
            graph[u].push_back(v);
            deg[v]++;
        }

        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            if(deg[i] == 0){
                q.push({i,time[i]});
            }
        }

        int tot = 0;
        while(!q.empty()){
            auto [node, tim] = q.front();
            q.pop();

            tot = max(tot, tim);
            for(auto nbr: graph[node]){
                deg[nbr]--;
                timetaken[nbr] = max(timetaken[nbr], tim);
                if(deg[nbr] == 0)q.push({nbr, timetaken[nbr] + time[nbr]});
            }
        }

        return tot;
    }
};