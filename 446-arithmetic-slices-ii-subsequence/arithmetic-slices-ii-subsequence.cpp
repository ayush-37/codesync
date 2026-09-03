class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int tot = 0;
        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < i; j++){
                int cnt = 0;
                long long diff = (long long)nums[i] - (long long)nums[j];
                if(dp[j].count(diff)){
                    cnt += dp[j][diff];
                }
                dp[i][diff] += (1 + cnt);
                tot += cnt;
            }
        }

        return tot;
    }
};