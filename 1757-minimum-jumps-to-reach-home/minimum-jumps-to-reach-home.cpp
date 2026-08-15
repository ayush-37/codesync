class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> st(forbidden.begin(), forbidden.end());
        queue<pair<int,int>> q;
        vector<int> vis(1e5,0);
        q.push({0,0});
        vis[0] = 1;
        int moves = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto [curr, jumpBack] = q.front();
                q.pop();
                if(curr == x)return moves;
                if(jumpBack == 0){
                    if(curr - b >= 0 && !st.count(curr-b) && vis[curr-b] == 0){
                        q.push({curr-b,1});
                        vis[curr-b] = 1;
                    }
                    if(!st.count(curr+a) && (curr+a < vis.size()) && vis[curr+a] == 0){
                        q.push({curr+a,0});
                        vis[curr+a] = 1;
                    }
                }
                else{
                    if(!st.count(curr+a) && (curr+a < vis.size()) && vis[curr+a] == 0){
                        q.push({curr+a,0});
                        vis[curr+a] = 1;
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};