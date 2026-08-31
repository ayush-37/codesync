class Solution {
public:
    using ll = long long;
    vector<vector<ll>> memo;
    vector<int> pref;
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        pref.assign(n+1,0);
        memo.assign(n+1,vector<ll>(n+1,-1));
        for(int i = 0; i < n; i++)pref[i+1] = pref[i] + stones[i];

        if((n-1) % (k-1) != 0)return -1;
        return (int)solve(0, n-1, k);
    }
    ll solve(int s, int e, int& k){
        if(s >= e)return 0; // single element or not element -> cost of merging = 0
        if(memo[s][e] != -1)return memo[s][e];

        ll ans = INT_MAX;
        for(int l = s; l < e; l+=k-1){
            ll temp = solve(s,l,k) + solve(l+1,e,k);
            ans = min(ans, temp);
        }
        // if the range [s, e] can be merged that is ((e-s+1)-1)%(k-1) == 0 then total cost will also include merging the range
        if((e-s) % (k-1) == 0)ans += pref[e+1] - pref[s];
        return memo[s][e] = ans;
    }
};