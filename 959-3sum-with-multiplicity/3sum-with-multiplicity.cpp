class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int M = 3002;
    vector<ll> fact,invFact;

    void computeFact(){
        fact.resize(M,0);
        fact[0] = 1;
        for(int i = 1; i < M; i++)fact[i] = (fact[i-1]*i)%MOD;
    }

    ll binPow(ll a, ll b){
        ll res = 1;
        while(b > 0){
            if(b%2)res = (res * a) % MOD;
            a = (a*a) % MOD;
            b/=2;
        }
        return res;
    }

    void computeInvFact(){
        invFact.resize(M,0);
        invFact[M-1] = binPow(fact[M-1], MOD-2);
        for(int i = M-2; i >= 0; i--)invFact[i] = (invFact[i+1]*(i+1)) % MOD;
    }

    ll nCr(ll n, ll r){
        if(r == 0 || r == n)return 1;
        if(r < 0 || r > n)return 0;

        return ((fact[n]*invFact[r])%MOD * invFact[n-r])%MOD;
    }

    int threeSumMulti(vector<int>& arr, int target) {
        computeFact();
        computeInvFact();

        vector<int> freq(101,0);
        for(int i = 0; i < arr.size(); i++){
            freq[arr[i]]++;
        }

        ll ans = 0;

        for(int a = 0; a < 101; a++){
            for(int b = a; b < 101 && a+b <= target; b++){
                int c = target - a - b;
                if(c < 0 || c > 100 || c < b) continue;

                if(a == b && a == c){
                    ans = (ans + nCr(freq[a], 3))%MOD;
                }
                else if(a == b && b != c){
                    ans = (ans + (nCr(freq[a],2) * freq[c])%MOD)%MOD;
                }
                else if(a != b && b == c){
                    ans = (ans + (nCr(freq[b],2) * freq[a])%MOD)%MOD;
                }
                else{
                    ans = (ans + (((freq[a]*freq[b])%MOD)*freq[c])%MOD)%MOD;    
                }
                                
            }

        }
        return (int)ans;
    }
};