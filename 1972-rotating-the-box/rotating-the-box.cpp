class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)ans[j][n-(i+1)] = boxGrid[i][j];
        }

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++){
                if(ans[j][i] == '*'){
                    int temp = 1;
                    while(temp <= cnt){
                        ans[j-temp][i] = '#';
                        temp++;
                    }
                    cnt = 0;
                }
                else if(ans[j][i] == '#'){
                    cnt++;
                    ans[j][i] = '.'; 
                }   
            }
            if(cnt != 0){
                int temp = 1;
                while(temp <= cnt){
                    ans[m-temp][i] = '#';
                    temp++;
                }
                cnt = 0;
            }
        }
        return ans;
    }
};