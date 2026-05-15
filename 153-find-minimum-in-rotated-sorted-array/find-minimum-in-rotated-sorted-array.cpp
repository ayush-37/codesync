class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mid;
        int ans = nums[0];
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[l] <= nums[mid]){
                ans = min(nums[l],ans);
                l = mid+1;
                continue;
            }
            
            if(nums[mid] <= nums[r]){
                ans = min(nums[mid],ans);
                r = mid-1;
                continue;
            }
        }
        return ans;
    }
};