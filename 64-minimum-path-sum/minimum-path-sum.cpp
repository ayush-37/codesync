class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});

        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = grid[0][0];

        while(!pq.empty()){
            auto [x,y] = pq.top();
            pq.pop();
            if(x == n-1 && y == m-1)break;

            int nx = x , ny = y+1;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(dis[x][y] + grid[nx][ny] < dis[nx][ny]){
                    dis[nx][ny] = dis[x][y] + grid[nx][ny];
                    pq.push({nx, ny});
                }
            }
            nx = x+1 , ny = y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(dis[x][y] + grid[nx][ny] < dis[nx][ny]){
                    dis[nx][ny] = dis[x][y] + grid[nx][ny];
                    pq.push({nx, ny});
                }
            }
        }

        return dis[n-1][m-1];
    }
};