class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v(m,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0)v[j] = 0;
                else v[j]+=matrix[i][j];
            }

            vector<int> temp(v.begin(),v.end());
            sort(temp.begin(),temp.end());
            for(int j = 0; j < m; j++){
                ans = max(ans,temp[j]*(m-j));
            }
        }
        return ans;
    }
}; 