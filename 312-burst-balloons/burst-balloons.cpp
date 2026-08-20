class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(nums, 1, n-2, dp);
    }

    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i > j)return 0;
        if(i == j)return nums[i-1]*nums[i]*nums[i+1];
        if(dp[i][j] != -1)return dp[i][j];

        dp[i][j] = INT_MIN;
        for(int k = i; k <= j; k++){
            int points = nums[i-1]*nums[k]*nums[j+1];
            dp[i][j] = max(dp[i][j], points + solve(nums,i,k-1,dp) + solve(nums,k+1,j,dp));
        }
        return dp[i][j];
    }
};