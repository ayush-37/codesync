class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    vector<int> dir;
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        dir = {-1,0,1};

        return solve(0,0,m-1,grid);
    }
    int solve(int r, int c1, int c2, vector<vector<int>>& grid){
        if(r < 0 || r >= n || c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)return INT_MIN;

        if(dp[r][c1][c2] != -1)return dp[r][c1][c2];

        int che = grid[r][c1];
        if(c1 != c2)che += grid[r][c2];

        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                maxi = max(maxi, solve(r+1,c1+dir[i], c2 + dir[j], grid));
            }
        }

        if(maxi == INT_MIN)maxi = 0;
        return dp[r][c1][c2] = maxi + che;
    }
};