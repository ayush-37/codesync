class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1000000000 + 7;
        int n = nums.size(), q = queries.size();
        for(int i = 0; i < q; i++){
            for(int j = queries[i][0]; j <= queries[i][1]; j+=queries[i][2]){
                nums[j] = (int)((1LL*nums[j]*queries[i][3])%mod);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans^=nums[i];
        }
        return ans;
    }
};