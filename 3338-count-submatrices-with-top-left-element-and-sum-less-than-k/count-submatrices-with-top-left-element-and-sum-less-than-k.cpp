class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> sum(n,vector<long long> (m+1,0)), sumGrid(n,vector<long long> (m+1,0));
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= m; j++){
                sum[i][j] = sum[i][j-1] + grid[i][j-1];
                long long s1 = 0;
                if(i-1 >= 0)s1 += sumGrid[i-1][j];
                long long s2 = sum[i][j];

                sumGrid[i][j] = s1+s2;
            } 
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= m; j++){
                if(sumGrid[i][j] <= k)ans++;
            }
        }
        return ans;
    }
};