class Fancy {
    vector<long long> v;
    long long add;
    long long mul;
    long long mod;
public:
    Fancy() {
        add = 0;
        mul = 1;
        mod = 1e9+7;
    }

    long long modInv(long long a){
        long long pow = mod-2;
        long long res = 1;
        while(pow){
            if(pow&1)res = (res*a)%mod;
            a = (a*a)%mod;

            pow /= 2; 
        }
        return res;
    }
    
    void append(int val) {
        long long inv = modInv(mul);
        long long x = ((val - add + mod)%mod * inv)%mod;
        v.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add+inc)%mod;
    }
    
    void multAll(int m) {
        mul = (mul*m)%mod;
        add = (add*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx >= v.size())return -1;
        return (int)((v[idx]*mul + add)%mod);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */