class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), low  = nums[0], high = nums[n-1], ans = high-low;
        if(n == 1)return 0;

        for(int i = 0; i < n-1; i++){
            low = min(nums[0]+k,nums[i+1]-k);
            high = max(nums[i]+k,nums[n-1]-k);
            ans = min(ans,high-low);
        }
        return ans;
    }
};