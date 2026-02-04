class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN, psum = nums[0];
        for(int l = 0, p = 0, q = 0, r = 1; r < n; r++){
            psum += nums[r];
            if(nums[r] == nums[r-1]){
                psum = nums[r];
                l = r;
            }
            else if(nums[r] < nums[r-1]){
                // find peak
                if(r > 1 && nums[r-2] < nums[r-1]){
                    p = r-1;
                    while(l < q)psum -= nums[l++];
                    while(l+1 < p && nums[l] < 0)psum -= nums[l++];
                }
            }
            else{
                if(r > 1 && nums[r-2] > nums[r-1]){
                    // find valley
                    q = r-1; 
                }
            }
            if(l < p && p < q)ans = max(ans,psum);
        }
        return ans;
    }
};