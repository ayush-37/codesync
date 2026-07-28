class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), q = queries.size();
        vector<int> pxor(n+1,0);
        for(int i = 1; i <= n; i++){
            pxor[i] = pxor[i-1]^arr[i-1];
        }

        vector<int> ans;
        for(int i = 0; i < q; i++){
            int l = queries[i][0]+1, r = queries[i][1]+1;
            ans.push_back(pxor[r]^pxor[l-1]);
        }
        return ans;
    }
};