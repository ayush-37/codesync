class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pxor(n+1,0);
        for(int i = 0; i < n; i++){
            pxor[i+1] = pxor[i] ^ arr[i];
        }

        int ans = 0;
        unordered_map<int,int> mp;
        for(int i = 1; i < n; i++){
            
            for(int j = 0; j < i; j++){
                mp[pxor[i]^pxor[j]]++;
            }

            for(int j = i+1; j < n+1; j++){
                if(mp.count(pxor[j]^pxor[i])){
                    ans+=mp[pxor[j]^pxor[i]];
                }
            }
            mp.clear();
        }
        return ans;
    }
};