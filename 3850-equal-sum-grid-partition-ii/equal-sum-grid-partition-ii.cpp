class Solution {
public:
    using ll = long long;
    bool check(int row, int col, int r, int c){
        if(row == 1){
            return (c == 0 || c == col-1);
        }
        if(col == 1){
            return (r == 0 || r == row-1);
        }
        return true;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<ll> pRow(n,0), pCol(m,0);
        unordered_map<ll, vector<pair<int,int>>> pos;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pRow[i] += grid[i][j];
                pCol[j] += grid[i][j];

                pos[grid[i][j]].push_back({i,j});

            }
        }

        for(int i = 1; i < n; i++)pRow[i] += pRow[i-1];
        for(int i = 1; i < m; i++)pCol[i] += pCol[i-1];

        ll tot = pRow[n-1];
        for(int i = 0; i < n-1; i++){
            ll x = pRow[i];
            ll y = tot-pRow[i];
            if(x == y)return true;
            else{
                if(x > y){
                    ll z = x-y;
                    if(pos.count(z)){
                        for(auto &[r,c]: pos[z]){
                            if(r > i)continue;
                            int row = i+1, col = m;
                            if(check(row,col,r,c))return true;
                        }
                    }
                }
                else{
                    ll z = y-x;
                    if(pos.count(z)){
                        for(auto &[r,c]: pos[z]){
                            if(r <= i)continue;
                            int row = n-i-1, col = m;
                            int nr = r - (i+1);
                            if(check(row,col,nr,c))return true;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < m-1; i++){
            ll x = pCol[i];
            ll y = tot-pCol[i];
            if(x == y)return true;
            else{
                if(x > y){
                    ll z = x-y;
                    if(pos.count(z)){
                        for(auto &[r,c]: pos[z]){
                            if(c > i)continue;
                            int row = n, col = i+1;
                            if(check(row,col,r,c))return true;
                        }
                    }
                }
                else{
                    ll z = y-x;
                    if(pos.count(z)){
                        for(auto &[r,c]: pos[z]){
                            if(c <= i)continue;
                            int row = n, col = i+1;
                            int nc = c - (i+1);
                            if(check(row,col,r,nc))return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};