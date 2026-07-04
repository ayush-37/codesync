class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                auto [x,y] = q.front();
                q.pop();
                if(x+1 < n && dist[x+1][y] > dist[x][y] + 1){
                    dist[x+1][y] = dist[x][y] + 1;
                    q.push({x+1,y});
                }
                if(y+1 < m && dist[x][y+1] > dist[x][y] + 1){
                    dist[x][y+1] = dist[x][y] + 1;
                    q.push({x,y+1});
                }
                if(x-1 >= 0 && dist[x-1][y] > dist[x][y] + 1){
                    dist[x-1][y] = dist[x][y] + 1;
                    q.push({x-1,y});
                }
                if(y-1 >= 0 && dist[x][y-1] > dist[x][y] + 1){
                    dist[x][y-1] = dist[x][y] + 1;
                    q.push({x,y-1});
                }
            }
        }

        int s = 0, e = min(dist[0][0],dist[n-1][m-1]), mid, ans = -1;
        while(s <= e){
            mid = s + (e-s)/2;
            if(canReach(dist,mid)){
                ans = mid;      // remember this valid answer
                s = mid + 1;  // try to do even better
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }

    bool canReach(vector<vector<int>>& dist, int mid){
        int n = dist.size(), m = dist[0].size();
        if(dist[0][0] < mid || dist[n-1][m-1] < mid)return false;

        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(x == n-1 && y == m-1)return true;

            for(int i = 0; i < 4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(valid(nx,ny,n,m) && vis[nx][ny] == 0 && dist[nx][ny] >= mid){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return false;
    }
    bool valid(int nx, int ny, int n, int m){
        if(nx >= 0 && nx < n && ny >= 0 && ny < m)return true;
        else return false;
    }
};