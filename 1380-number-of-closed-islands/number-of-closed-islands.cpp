class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> dir = {-1,0,1,0,-1};
        int ans = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    bool noTouch = !(i == 0 || i == n-1 || j == 0 || j == m-1);
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++){
                            int nx = x + dir[k];
                            int ny = y + dir[k+1];

                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && vis[nx][ny] == 0){
                                q.push({nx,ny});
                                vis[nx][ny] = 1;
                                if(nx == 0 || nx == n-1 || ny == 0 || ny == m-1)noTouch = false;
                            }
                        }
                    }

                    if(noTouch)ans++;
                }
            }
        }
        return ans;
    }
};