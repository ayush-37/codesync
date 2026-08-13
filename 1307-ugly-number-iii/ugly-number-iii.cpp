class Solution {
public:
    using ll = long long;
    int nthUglyNumber(int n, int a, int b, int c) {
        ll s = 1, e = 2e9, ans = 0;

        ll ab = lcm(1ll*a, 1ll*b);
        ll bc = lcm(1ll*b, 1ll*c);
        ll ac = lcm(1ll*a, 1ll*c);
        ll abc = lcm(1ll*a, bc);

        while(s <= e){
            int m = s + (e-s)/2;
            ll na = m/a, nb = m/b, nc = m/c;
            ll nab = m/ab, nbc = m/bc, nac = m/ac;
            ll nabc = m/abc;

            ll tot = na + nb + nc - nab - nbc - nac + nabc;
            if(tot >= (ll)n){
                ans = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return ans;
    }
};