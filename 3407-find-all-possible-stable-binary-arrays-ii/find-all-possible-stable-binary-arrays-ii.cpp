class Solution {
const int MOD = 1e9+7;
vector<long long> Fact = vector<long long>(2005);
vector<long long> invFact = vector<long long>(2005);

long long modPow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1LL)res = (res*a)%MOD;
        a = (a*a)%MOD;
        b = b>>1;
    }
    return res;
}

long long starAndBar(long long N, long long K, long long L){
    long long Np = N-K;
    long long ans = 0;

    for(int i = 0; i <= K; i++){
        long long remain = Np - i*1LL*L;
        if(remain < 0)break;

        long long term = (nCr(K,i)*nCr(remain + K - 1,K-1))%MOD;
        if(i%2 == 0){
            ans = (ans+term)%MOD;
        }
        else ans = (ans -term + MOD)%MOD;
    }
    return ans%MOD;
}

void init(){
    Fact[0] = 1;
    for(int i = 1; i < 2005; i++)Fact[i] = (Fact[i-1]*i)%MOD;
    invFact[2004] = modPow(Fact[2004],MOD-2);
    for(int i = 2003; i >= 0; i--)invFact[i] = (invFact[i+1]*(i+1))%MOD;
}

long long nCr(long long n, long long r){
    if(r < 0 || r > n) return 0;
    return Fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
}

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        if(zero > one)swap(zero,one);
        init();
        
        int minmBlocks = (zero+limit-1)/limit; // k blocks
        long long ans = 0;

        long long kMinus1 = 0;
        long long k = starAndBar(zero,minmBlocks,limit);
        long long kPlus1 = starAndBar(zero,minmBlocks+1,limit);

        for(int i = minmBlocks; i <= zero+1; i++){
            ans = (ans + ((kMinus1 + 2*k + kPlus1)%MOD)*(starAndBar(one,i,limit)))%MOD;
            kMinus1 = k;
            k = kPlus1;
            kPlus1 = starAndBar(zero,i+2,limit);
        }
        return ans;
    }
};