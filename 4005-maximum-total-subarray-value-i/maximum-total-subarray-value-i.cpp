class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = INT_MAX;
        long long maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mini = min(mini,(long long)nums[i]);
            maxi = max(maxi,(long long)nums[i]);
        }
        long long ans = (long long)k*(abs(maxi-mini));
        return ans;
    }
};