class Solution {
public:
    int t, n;
    vector<int> dp, nums;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        this->nums = nums;

        int sum = 0;
        for(auto x: nums) sum += x;
        if(sum % k != 0)return false;

        t = sum / k;
        for (int x : nums) {
            if (x > t)
                return false;
        }

        dp.assign(1<<n,-1);
        return solve(0,0,k) == 1;
    }

    bool solve(int msk, int currSum, int k){
        if(msk == (1<<n) - 1){
            return true;
        }
        if(currSum == t)return solve(msk,0,k-1);

        if(k == 0)return false;

        if(dp[msk] != -1)return dp[msk];

        for(int i = 0; i < n; i++){
            if(msk & (1<<i))continue;
            if(nums[i] + currSum > t)continue;

            if(solve(msk | (1<<i), currSum + nums[i], k)){
                dp[msk] = 1;
                return dp[msk];
            }
        }

        return dp[msk] = 0;
    }
};