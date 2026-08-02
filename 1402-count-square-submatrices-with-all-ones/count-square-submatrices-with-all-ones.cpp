class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sq(n+1,vector<int>(m+1,0));
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(matrix[i-1][j-1] == 1){
                    sq[i][j] = min({sq[i-1][j],sq[i][j-1],sq[i-1][j-1]})+1;
                    cnt += sq[i][j];
                }
            }
        }
        return cnt;
    }
};