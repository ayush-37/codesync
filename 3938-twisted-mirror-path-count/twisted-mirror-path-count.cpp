class Solution {
public:
    int n, m, top, left;
    vector<vector<vector<int>>> memo;
    const int MOD = 1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        top = 0, left = 1;
        memo.assign(n,vector<vector<int>>(m, vector<int>(2,-1)));
        return solve(0,0,grid,0);
    }

    int solve(int i, int j, vector<vector<int>>& grid, int comeFrom){
        if(i >= n || j >= m)return 0;
        if(i == n-1 && j == m-1){
            return 1;
        }

        if(memo[i][j][comeFrom] != -1)return memo[i][j][comeFrom];

        if(grid[i][j] == 1){
            if(comeFrom == left){
                return solve(i+1,j,grid,top);
            }
            else{
                return solve(i,j+1,grid,left);
            }
        }

        int tot = 0;
        tot = ((tot + solve(i+1,j,grid,top))%MOD + (solve(i,j+1,grid,left))) % MOD;
        return memo[i][j][comeFrom] = tot;

    }
};