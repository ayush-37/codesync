class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int sz = 1 << n;
        unordered_map<int, vector<ll>> mp;
        for(int i = 1; i < sz; i++){
            int x = i, cnt = 0;
            ll l = 1;
            for(int j = 0; j < 16; j++){
                if((x>>j) & 1 == 1){
                    l = lcm(l, coins[j]*1LL);
                    cnt++;
                }
            }
            mp[cnt].push_back(l);
        }
        ll s = *min_element(coins.begin(), coins.end());
        ll e = s*k;
        ll ans = -1;
        while(s <= e){
            ll mid = s + (e-s)/2;
            ll tot = 0;
            bool flag = true;
            for(int i = 1; i < sz; i++){
                for(auto x: mp[i]){
                    if(flag)tot += (mid/x);
                    else tot -= (mid/x);
                }
                if(flag)flag = false;
                else flag = true;
            }

            if(tot < k){
                s = mid + 1;
            }
            else{
                ans = mid;
                e = mid - 1;
            }
        }

        return ans;
    }
};