class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq(10005, 0);
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        sort(nums.begin(),nums.end());
        auto last = unique(nums.begin(),nums.end());
        nums.erase(last,nums.end());

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));

        dp[0][1] = nums[0]*freq[nums[0]];
        dp[0][0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i]-1 == nums[i-1]){
                dp[i][1] = nums[i]*freq[nums[i]] + dp[i-1][0];
                dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
            }
            else{
                dp[i][1] = (nums[i]*freq[nums[i]]) + max(dp[i-1][0], dp[i-1][1]);
                dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
            }

        }

        return max(dp[n-1][0],dp[n-1][1]);
    }
};