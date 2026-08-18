class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> f(n,vector<int>(n,-1));

        for(int i = 0; i < preferences.size(); i++){
            for(int j = 0; j < preferences[i].size(); j++){
                int u = i;
                int v = preferences[i][j];
                f[u][v] = j;
            }
        }
        unordered_map<int,int> partners;

        for(auto x: pairs){
            int u = x[0];
            int v = x[1];
            partners[u] = v;
            partners[v] = u;
        }

        auto prefer = [&](int x, int y){
            for(auto u: preferences[x]){
                if(u == y)continue;
                int pu = partners[u];
                if(f[x][u] < f[x][y] && f[u][x] < f[u][pu]){
                    return true;
                }
            }
            return false;
        };
        int cnt = 0;
        for(auto p: pairs){
            int x = p[0], y = p[1];
            if(f[x][y] != 0){
                if(prefer(x,y))cnt++;
            }
            if(f[y][x] != 0){
                if(prefer(y,x))cnt++;
            }
        }
        return cnt;
    }
};