class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;
    pair<ll,ll> def = {LLONG_MIN, LLONG_MAX};
    vector<vector<pair<ll,ll>>> memo;;

    pair<ll,ll> solve(int x, int y, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();

        if(x == n-1 && y == m-1){
            return memo[x][y] = {(ll)grid[x][y], grid[x][y]};
        }

        if(memo[x][y] != def)return memo[x][y];

        ll curr = grid[x][y];
        ll maxi = LLONG_MIN, mini = LLONG_MAX;
        if(x+1 < n){
            pair<ll,ll> p = solve(x+1,y,grid);
            maxi = max({maxi, p.first*curr, p.second*curr});
            mini = min({mini, p.first*curr, p.second*curr});
        }
        if(y+1 < m){
            pair<ll,ll> p = solve(x,y+1,grid);
            maxi = max({maxi, p.first*curr, p.second*curr});
            mini = min({mini, p.first*curr, p.second*curr});
        }

        return memo[x][y] = {maxi,mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memo.assign(n,vector<pair<ll,ll>> (m,{LLONG_MIN,LLONG_MAX}));
        pair<ll,ll> ans = solve(0,0,grid);
        if(ans.first < 0)return -1;
        else return (int)(ans.first%mod);
    }
};