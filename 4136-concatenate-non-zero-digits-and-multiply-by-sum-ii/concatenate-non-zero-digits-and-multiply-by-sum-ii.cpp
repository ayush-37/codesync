const int MAX_N = 100001;
const int mod = 1e9+7;
long long pow10[MAX_N];

// init runs only once for all test cases
int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % mod;
    }
    return 0;
}();

class Solution {
public:
    using ll = long long;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), r = 0, mod = 1e9+7;
        vector<ll> indToNo(n+1,0);
        vector<ll> noToSize(n+1,0);
        vector<int> presum(n+1,0);
        for(int i = 0; i < n; i++){
            r = s[i] - '0';
            if(r != 0){
                presum[i+1] = presum[i]+r;
                indToNo[i+1] = (((indToNo[i]*10)%mod) + r)%mod;
                noToSize[i+1] = noToSize[i]+1;
            }
            else{
                presum[i+1] = presum[i];
                indToNo[i+1] = indToNo[i];
                noToSize[i+1] = noToSize[i];
            }
            cout<<indToNo[i+1]<<" ";
        }
        int q = queries.size();
        vector<int> ans(q,0);
        for(int i = 0;i < q; i++){
            int l = queries[i][0], r = queries[i][1]+1;
            int len = noToSize[r] - noToSize[l];
            long long val = (indToNo[r] - indToNo[l]*pow10[len]%mod + mod)%mod;
            long long sum = presum[r] - presum[l];
            ans[i] = (val*sum)%mod;
        }
        return ans;
    }
};