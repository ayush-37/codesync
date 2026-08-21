class Solution {
public:
    int n, m;
    vector<int> dx;
    vector<int> dy;
    vector<vector<int>> vis, dis;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        vis.resize(n,vector<int>(m,0));
        dis.resize(n,vector<int>(m,0));
        dx = {0,0,1,-1};
        dy = {1,-1,0,0};

        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0){
                    ans = max(ans,dfs(i,j,matrix));
                }
                else ans = max(ans,dis[i][j]);
            }
        }

        return ans;
    }

    int dfs(int x, int y, vector<vector<int>>& matrix){
        if(dis[x][y] != 0)return dis[x][y];
        int temp = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(vis[nx][ny] != 0){
                    temp = max(temp, dis[nx][ny]);
                }
                else{
                    if(matrix[x][y] < matrix[nx][ny]){
                        temp = max(temp,dfs(nx,ny,matrix));
                    }
                }
            }
        }
        return dis[x][y] = temp + 1;
    }

};