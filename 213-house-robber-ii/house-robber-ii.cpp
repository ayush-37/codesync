class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        
        vector<int> dp1(n+1,0), dp2(n+1,0);
        for(int i = 1; i < n; i++){
            int take = nums[i-1] + (i >= 2? dp1[i-2]:0);
            int notTake = dp1[i-1];
            dp1[i] = max(take,notTake);
        }
        for(int i = 2; i <= n; i++){
            int take = nums[i-1] + (i >= 2? dp2[i-2]:0);
            int notTake = dp2[i-1];
            dp2[i] = max(take,notTake);
        }

        return max(dp1[n-1],dp2[n]);
    }
};