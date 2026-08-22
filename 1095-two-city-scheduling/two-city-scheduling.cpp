class Solution {
public:
    using ll = long long;
    vector<vector<vector<ll>>> v;
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        v.resize(2*n+1, vector<vector<ll>>(n+1,vector<ll>(n+1,-1)));
        return solve(0,n,n,costs);
    }
    ll solve(int i, int a, int b, vector<vector<int>>& costs){
        if(a == 0 && b == 0)return 0;
        if(a < 0 || b < 0)return INT_MAX;
        if(v[i][a][b] != -1)return v[i][a][b];
        ll at = INT_MAX, bt = INT_MAX;
        if(a != 0)at = costs[i][0] + solve(i+1, a-1, b, costs);
        if(b != 0)bt = costs[i][1] + solve(i+1, a, b-1, costs);

        return v[i][a][b] = min(at,bt);
    }
};