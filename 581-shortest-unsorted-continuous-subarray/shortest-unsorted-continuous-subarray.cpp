class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1, r = -1, n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i+1]){
                l = i;
                break;
            }
        }
        if(l == -1)return 0;
        for(int i = n-1; i > l; i--){
            if(nums[i] < nums[i-1]){
                r = i;
                break;
            }
        }

        int mn = INT_MAX, mx = INT_MIN;
        for(int i = l; i <= r; i++){
            mn = min(mn,nums[i]);
            mx = max(mx,nums[i]);
        }

        while(l > 0 && nums[l-1] > mn)l--;
        while(r < n-1 && nums[r+1] < mx)r++;

        return r-l+1;
    }
};