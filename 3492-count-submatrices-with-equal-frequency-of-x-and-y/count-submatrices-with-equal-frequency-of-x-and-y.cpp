class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<int,int>>> msk(n,vector<pair<int,int>>(m));
        for(int i = 0; i < n; i++){
            int x = 0, y = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X')x++;
                else if(grid[i][j] == 'Y') y++;

                int tx = x, ty = y;
                if(i-1>=0){
                    tx += msk[i-1][j].first;
                    ty += msk[i-1][j].second;
                }
                msk[i][j] = {tx,ty};
            }
        }
        
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(msk[i][j].first != 0 && msk[i][j].first == msk[i][j].second)ans++;
            }
        }
        return ans;

    }
};