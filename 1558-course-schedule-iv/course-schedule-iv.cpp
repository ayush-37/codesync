class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<vector<bool>> isReq(n,vector<bool>(n,false));

        for(auto x: prerequisites){
            graph[x[0]].push_back(x[1]);
        }

        for(int i = 0; i < n; i++){
            int source = i;
            queue<int> q;
            vector<int> vis(n,0);
            q.push(source);
            vis[source] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto nbr: graph[node]){
                    isReq[source][nbr] = true; 
                    if(vis[nbr] == 0){
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
        }
        int len = queries.size();
        vector<bool> ans(len,false);
        for(int i = 0; i < len; i++){
            ans[i] = isReq[queries[i][0]][queries[i][1]];
        }
        return ans;

    }
};