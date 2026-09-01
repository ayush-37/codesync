class Solution {
public:
    using ll = long long;
    const int MOD = 1e9+7;
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());

        int n = packages.size();
        vector<ll> pref(n+1,0);
        for(int i = 0; i < n; i++)pref[i+1] = pref[i] + packages[i];


        for(auto& x: boxes){
            sort(x.begin(),x.end());
        }

        ll ans = LLONG_MAX;
        for(int i = 0; i < boxes.size(); i++){
            if(boxes[i].back() < packages.back())continue;

            int st = 0;
            ll temp = 0;
            for(int j = 0; j < boxes[i].size(); j++){
                // cout<<boxes[i][j]<<" ";
                auto itr = upper_bound(packages.begin() + st, packages.end(), boxes[i][j]);
                if(itr == packages.begin())continue;

                itr--;

                int x = st, y = itr - packages.begin();
                temp += 1LL*boxes[i][j]*(y-x+1)  - (pref[y+1] - pref[x]);
                // cout<<x<<" "<<y<<endl;
                st = y+1;
            }

            if(temp < ans){
                ans = temp;
                // cout<<endl<<i<<"  "<<ans<<endl;
            }
        }

        return ans == LLONG_MAX ? -1 : ans % MOD;
    }
};