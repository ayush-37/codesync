class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<int>> ans(n,vector<int>(n,-1));
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        if(q.size() == 0 || q.size() == n*n)return -1;

        vector<int> dir = {-1,0,1,0,-1};
        int dis = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front();
                ans[x][y] = dis;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nx = x + dir[i], ny = y + dir[i+1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && vis[nx][ny] == 0){
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
            dis++;
        }
        return dis-1;
    }
};