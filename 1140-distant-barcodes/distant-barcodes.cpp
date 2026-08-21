class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> ans(n);
        unordered_map<int,int> mp;
        int ind = 0;
        for(auto x: barcodes)mp[x]++;
        vector<pair<int,int>> pairs;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            int key = itr->first, val = itr->second;
            pairs.push_back({val,key});
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
        for(auto [v,x]: pairs){
            while(v--){
                ans[ind] = x;
                ind += 2;
                if(ind >= n)ind = 1;
            }
        }
        return ans;
    }
};