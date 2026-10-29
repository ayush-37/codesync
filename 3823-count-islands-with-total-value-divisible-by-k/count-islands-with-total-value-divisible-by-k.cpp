class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<int> dir = {-1,0,1,0,-1};
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j])continue;

                if(grid[i][j] == 0){
                    vis[i][j] = 1;
                }
                else {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    long long cnt = 0;
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        cnt += (1LL * grid[x][y]);
                        for(int i = 0; i < 4; i++){
                            int nx = x + dir[i], ny = y + dir[i+1];
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] != 0){
                                vis[nx][ny] = 1;
                                q.push({nx,ny});
                            }
                        }
                    }
                    if(cnt % k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};