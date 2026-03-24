class Solution {
public:
    using ll = long long;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        ll prod = 1;
        vector<vector<int>> pref(n,vector<int>(m+1,0));
        vector<vector<int>> suf(n,vector<int>(m+1,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pref[i][j] = prod;
                prod = (prod*grid[i][j])%12345;
            }
        }

        prod = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                suf[i][j] = prod;
                prod = (prod*grid[i][j])%12345;
            }
        }

        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = (pref[i][j]*suf[i][j])%12345;
            }
        }
        return ans;
    }
};