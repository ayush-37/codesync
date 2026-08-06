class Solution {
public:
    vector<int> dir;
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxi = 0, n = grid.size(), m = grid[0].size();
        dir = {-1,0,1,0,-1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0)continue;
                else{
                    vector<vector<int>> vis(n,vector<int>(m,0));
                    dfs(i,j,0,maxi,grid,vis);
                }
            }
        }
        return maxi;
    }

    void dfs(int x, int y, int curr, int& maxi, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || vis[x][y] == 1 || grid[x][y] == 0){
            maxi = max(maxi,curr);
            return;
        }

        curr += grid[x][y];

        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i];
            int ny = y + dir[i+1];
            dfs(nx,ny,curr,maxi,grid,vis);
        }
        vis[x][y] = 0;
    }
};