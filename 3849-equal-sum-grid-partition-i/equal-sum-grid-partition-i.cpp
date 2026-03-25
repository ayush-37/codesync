class Solution {
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<ll> pRow(n,0),pCol(m,0);
        ll tot = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pRow[i]+=grid[i][j];
                pCol[j]+=grid[i][j];
                tot+=grid[i][j];
            }
        }
        ll prev = 0;
        for(int i = 0; i < n; i++){
            prev += pRow[i];
            if(tot == 2*prev)return true;
        }
        prev = 0;
        for(int i = 0; i < m; i++){
            prev += pCol[i];
            if(tot == 2*prev)return true;
        }

       return false; 
    }
};