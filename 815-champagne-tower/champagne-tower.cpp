class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> curr(101,vector<double>(101,0));
        curr[0][0] = poured;
        for(int i = 0; i < query_row; i++){
            for(int j = 0; j <= i; j++){
                if(curr[i][j] > 1.0){
                    double divided = (curr[i][j] - 1)/2;
                    curr[i+1][j] += divided;
                    curr[i+1][j+1] += divided;
                    curr[i][j] = 1.0;
                }
            }
            
        }
        return min(1.0,curr[query_row][query_glass]);
    }
};