class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> ans;

        if(n == 1 || m == 1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++)ans.push_back({i,j});
            }
            return ans;
        }

        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));

        // case 1 pacific

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            pacific[i][0] = 1;
            q.push({i,0});
        }
        for(int i = 0; i < m; i++){
            pacific[0][i] = 1;
            q.push({0,i});
        }
        vector<int> dir{-1,0,1,0,-1};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && pacific[nx][ny] == 0 && heights[nx][ny] >= heights[x][y]){
                    pacific[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }

        }

        // case 2 atlantic
        for(int i = 0; i < n; i++){
            atlantic[i][m-1] = 1;
            q.push({i,m-1});
        }
        for(int i = 0; i < m; i++){
            atlantic[n-1][i] = 1;
            q.push({n-1,i});
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && atlantic[nx][ny] == 0 && heights[nx][ny] >= heights[x][y]){
                    atlantic[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }

        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j])ans.push_back({i,j});
            }
        }
        return ans;

    }
};