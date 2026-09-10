class Solution {
public:
    using ll = long long;
    string nearestPalindromic(string n) {
        // next palindrome smallest palindrome just greater than n
        ll nt = stoll(n);
        ll st = nt+1, en = LLONG_MAX, mid, next, prev;
        while(st <= en){
            mid = st + (en - st)/2;
            ll pal = createPal(to_string(mid), n);
            if(pal > nt){
                next = pal;
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }

        // prev palindrome biggest no just less than n
        st = 0, en = nt-1;
        while(st <= en){
            mid = st + (en - st) / 2;
            ll pal = createPal(to_string(mid), n);
            if(pal < nt){
                prev = pal;
                st = mid+1;
            }
            else{
                en = mid-1;
            }
        }

        if(abs(prev - nt) <= abs(next - nt))return to_string(prev);
        else return to_string(next);
    }

    ll createPal(string x, string& n){
        int len = x.size();
        int halfLen = (len + 1)/2;
        string pref = x.substr(0,halfLen);
        int sz = pref.size();
        int i = len % 2? sz-2: sz-1;
        while(i >= 0){
            pref.push_back(x[i]);
            i--;
        }

        return stoll(pref);
    }
};