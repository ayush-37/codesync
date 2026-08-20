class Solution {
public:
    using ll = long long;
    int countDigitOne(int n) {
        int cnt = 0;
        for(ll i = 1; i <= n; i *= 10){
            ll d = i*10;
            cnt += (n/d)*i + min(max(0LL,n%d - i + 1), i);
        }
        return cnt;
    }
};