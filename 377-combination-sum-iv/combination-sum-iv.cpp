class Solution {
public:
    vector<vector<int>> memo;

    int combinationSum4(vector<int>& nums, int target) {
        memo.resize(201,vector<int>(1001,-1));
        return solve(0,target,nums);
    }

    int solve(int idx, int target, vector<int>& nums){
        if(target == 0)return 1;
        if(idx >= (int)nums.size() || target < 0)return 0;

        if(memo[idx][target] != -1)return memo[idx][target];

        int take = solve(0,target-nums[idx],nums);
        int not_take = solve(idx+1,target,nums);

        return memo[idx][target] = take + not_take;
    }


};