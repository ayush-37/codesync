class Solution {
public:
    const int MOD = 1e9 + 7;
    long long fact[100002], invFact[100002];

    // Fast exponentiation
    long long modPow(long long a, long long b) {
        long long result = 1;
        while (b) {
            if (b & 1) result = result * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return result;
    }

    // Precompute factorials and inverse factorials
    void precompute(int maxN) {
        // Factorials
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = fact[i-1] * i % MOD;
        }
        
        // Inverse factorials using Fermat's Little Theorem
        invFact[maxN] = modPow(fact[maxN], MOD - 2);
        // FIXED: Go backwards from maxN-1 down to 0
        for (int i = maxN - 1; i >= 0; i--) {
            invFact[i] = invFact[i+1] * (i+1) % MOD;
        }
    }

    // O(1) query after preprocessing
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }   
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        // First, find the depth of the tree
        int dep = 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        q.push(1);
        vector<int> vis(n+1,0);
        vis[1] = 1;
        int s = 1;
        while(!q.empty()){
            s = q.size();
            for(int i = 0; i < s; i++){
                int node = q.front();
                q.pop();
                for(auto x: mp[node]){
                    if(vis[x] == 0){
                        q.push(x);
                        vis[x] = 1;
                    }
                    
                }
            }
            dep++;
        }
        
        dep--;
        // Precompute up to dep (not fixed 100001)
        precompute(dep);
        
        long long ans = 0;
        for(int i = 1; i <= dep; i += 2){
            ans = (ans + nCr(dep, i)) % MOD;
        }
        return ans;
    }
};