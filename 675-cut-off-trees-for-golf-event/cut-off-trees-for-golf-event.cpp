class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size();
        if(n == 1 && m == 1)return 0;
        if(forest[0][0] == 0)return -1;

        vector<pair<int,pair<int,int>>> trees;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(forest[i][j] > 1){
                    trees.push_back({forest[i][j], {i,j}});
                }
            }
        }

        sort(trees.begin(), trees.end());

        auto bfs = [&](int sx, int sy, int dx, int dy){
            vector<vector<int>> vis(n, vector<int>(m,0));

            vis[sx][sy] = 1;
            vector<int> dir = {-1,0,1,0,-1};

            queue<pair<int,int>> q;
            int lev = 0;
            q.push({sx, sy});
            while(!q.empty()){
                int sz = q.size();
                while(sz--){
                    auto [x, y] = q.front();
                    q.pop();

                    if(x == dx && y == dy)return lev;
                    for(int i = 0; i < 4; i++){
                        int nx = x + dir[i], ny = y + dir[i+1];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && forest[nx][ny] > 0){
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
                lev++;
            }

            return -1;
        };

        int x = 0, y = 0;
        int total = 0;
        for(int i = 0; i < trees.size(); i++){
            auto [r,c] = trees[i].second;

            int cost = bfs(x,y,r,c);
            if(cost == -1){
                return -1;
            }

            x = r, y = c;
            total += cost;
        }
        return total;
    }
};