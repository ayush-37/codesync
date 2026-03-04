class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size(),m = mat[0].size();
        for(int i = 0; i < n; i++){
            bool mainflag = false;
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    bool flag = false;
                    for(int k = 0; k < m; k++){
                        if(k != j && mat[i][k] == 1){
                            flag = true;
                            mainflag = true;
                            break;
                        }
                    }
                    if(flag)break;
                    for(int k = 0; k < n; k++){
                        if(k != i && mat[k][j] == 1){
                            flag = true;
                            break;
                        }
                    }

                    if(!flag)ans++;
                }
                if(mainflag)break;
            }
        }
        return ans;
    }
};