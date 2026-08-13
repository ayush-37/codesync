class Solution {
public:
    using ll = long long;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n,0);
        ugly[0] = 1;
        int m = primes.size();
        vector<int> idx(m,0);
        vector<ll> nxt(m,0);
        for(int i = 0; i < m; i++)nxt[i] = primes[i];

        for(int i = 1; i < n; i++){
            ll mini = INT_MAX;
            for(int j = 0; j < m; j++)mini = min(mini,nxt[j]);
            ugly[i] = (int)mini;
            
            for(int j = 0; j < m; j++)if(nxt[j] == mini){
                idx[j]++;
                nxt[j] = 1LL*primes[j]*ugly[idx[j]];
            }
        }

        return ugly[n-1];
    }
};