class Solution {
public:
    using ll = long long;
    vector<vector<int>> memo;
    int n;
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        n = nums.size();
        memo.resize(n,vector<int>(k+1,INT_MAX));
        return solve(0,k,nums);
    }
    int solve(int i, int k, vector<int>& nums){
        if(i == n)return 0;
        if(k < 0)return INT_MAX;
        if(memo[i][k] != INT_MAX)return memo[i][k];

        long long ans = INT_MAX;
        int sum = 0, maxi = nums[i];
        for(int j = i; j < n; j++){
            sum += nums[j];
            maxi = max(maxi, nums[j]);

            int wasted = maxi*(j-i+1) - sum;

            ans = min(ans, (ll)solve(j+1,k-1,nums) + (ll)wasted);
        }

        return memo[i][k] = (int)ans;

    }

};