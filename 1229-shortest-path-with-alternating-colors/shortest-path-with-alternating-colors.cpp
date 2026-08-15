class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        for(auto r: redEdges){
            red[r[0]].push_back(r[1]);
        }
        for(auto b: blueEdges){
            blue[b[0]].push_back(b[1]);
        }

        vector<vector<int>> dis(n,vector<int>(2,-1));
        dis[0][0] = 0, dis[0][1] = 0;
        queue<pair<int,int>> q;
        q.push({0,0}); // red
        q.push({0,1}); // blue
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [node, isBlue] = q.front();
                q.pop();
                if(isBlue){
                    for(auto nbr: red[node]){
                        if(dis[nbr][0] == -1){
                            dis[nbr][0] = dis[node][1]+1;
                            q.push({nbr,0});
                        }
                    }
                }
                else{
                    for(auto nbr: blue[node]){
                        if(dis[nbr][1] == -1){
                            dis[nbr][1] = dis[node][0]+1;
                            q.push({nbr,1});
                        }
                    }
                }
            }
        }
        vector<int> ans(n,-1);
        for(int i = 0; i < n; i++) {

            if(dis[i][0] == -1)
                ans[i] = dis[i][1];

            else if(dis[i][1] == -1)
                ans[i] = dis[i][0];

            else
                ans[i] = min(dis[i][0], dis[i][1]);
        }

        return ans;
    }
};