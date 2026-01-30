class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int r = nums.size()-1;
        while(r >= 1 && nums[r] > nums[r-1]){
            r--;
        }
        return r;
    }
};