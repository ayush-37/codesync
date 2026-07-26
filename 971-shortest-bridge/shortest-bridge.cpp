class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<int>& dir,vector<pair<int,int>>& p){
        
        p.push_back({i,j});

        for(int k = 0; k < 4; k++){
            int x = i+dir[k], y = j+dir[k+1];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1){
                if(vis[x][y] == 0){
                    vis[x][y] = 1;
                    dfs(x,y,grid,vis,dir,p);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> dir{0,1,0,-1,0};
        vector<pair<int,int>> a,b;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    vis[i][j] = 1;
                    if(cnt == 0)dfs(i,j,grid,vis,dir,a);
                    else dfs(i,j,grid,vis,dir,b);
                    cnt++;
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < a.size(); i++){
            int x1 = a[i].first, y1 = a[i].second;
            for(int j = 0; j < b.size(); j++){
                int x2 = b[j].first, y2 = b[j].second;
                ans = min(ans,abs(x1-x2) + abs(y1-y2) - 1);
            }
        }
        return ans;
    }
};