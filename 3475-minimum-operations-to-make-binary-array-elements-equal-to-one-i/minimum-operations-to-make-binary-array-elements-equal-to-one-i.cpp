class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sw = 0, n = nums.size();
        for(int i = 2; i < n; i++){
            if(nums[i-2] == 0){
                sw++;
                nums[i-2] ^= 1;
                nums[i-1] ^= 1;
                nums[i] ^= 1;
            }
        }
        for(int i = n-1; i >= 0; i--)if(nums[i] == 0)return -1;
        return sw;
    }
};