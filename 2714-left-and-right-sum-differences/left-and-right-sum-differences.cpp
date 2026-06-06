class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        for(int i= 0; i < n; i++)r += nums[i];
        vector<int> ans(n,0);
        int l = 0;
        for(int i = 0; i < n; i++){
            r -= nums[i];
            ans[i] = abs(r-l);
            l+=nums[i];
        }
        return ans;
    }
};