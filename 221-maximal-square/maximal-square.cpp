/*

"The key insight is that if we're at cell (i,j) and it's a '1', the largest square ending at this cell depends on three neighboring positions:
    The cell above (i-1,j)
    The cell to the left (i,j-1)
    The cell diagonally above-left (i-1,j-1)

If all three can form squares of size at least k, then we can form a square of size k+1 at (i,j)."

*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans,solve(i,j,matrix,memo));
            }
        }
        return ans*ans;
    }

    int solve(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& memo){
        if(i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == '0')return 0;
        if(memo[i][j] != -1)return memo[i][j];

        int right = solve(i,j+1,matrix,memo);
        int down = solve(i+1,j,matrix,memo);
        int diag = solve(i+1,j+1,matrix,memo);

        memo[i][j] = 1 + min({right,down,diag});
        return memo[i][j];
    }
};