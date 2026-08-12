class Solution {
public:
    using ll = long long;
    const int mod = 1e9+7;

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll maxP = 0, maxS = 0;
        ll temp = 0, n = arr.size();
        for(ll i = 0; i < n; i++){
            temp += arr[i];
            maxP = max(maxP, temp);
        }
        temp = 0;
        for(ll i = n-1; i >= 0; i--){
            temp += arr[i];
            maxS = max(maxS, temp);
        }

        ll kad = 0, curr = 0, tot = 0;
        for(ll i = 0; i < n; i++){
            tot += arr[i];
            curr = max(0*1LL,curr+arr[i]);
            kad = max(kad, curr);
        }

       if(k == 1)return (int)(kad%mod);
       else if(k == 2)return (int)((maxP + maxS)%mod);
       else return (int)max({kad%mod, (maxP+maxS)%mod, (maxP+maxS+((k-2)*tot)%mod)%mod});
    }
};