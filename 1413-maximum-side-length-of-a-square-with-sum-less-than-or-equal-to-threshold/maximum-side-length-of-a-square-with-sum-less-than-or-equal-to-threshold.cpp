class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> psum(n+1,vector<int>(m+1,0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                psum[i][j] = psum[i][j-1] + mat[i-1][j-1];
            }
        }

        // vector<int> row(n+1,0), col(m+1,0);
        // for(int i = 1; i <= n; i++){
        //     row[i] = row[i-1] + psum[i][m];
        // }
        // for(int i = 1; i <= m; i++){
        //     col[i] = col[i-1] + psum[n][i];
        // }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int s = 1, e = min(m-j+1, n-i+1);
                while(s <= e){
                    int sq = s + (e-s)/2;
                    int sum = 0;
                    for(int l = i; l < i+sq; l++){
                        sum += (psum[l][j+sq-1] - psum[l][j-1]);
                    }

                    if(sum <= threshold){
                        ans = max(ans,sq);
                        s = sq+1;
                    }
                    else e = sq-1;
                }
            }
        }
        return ans;
    }
};