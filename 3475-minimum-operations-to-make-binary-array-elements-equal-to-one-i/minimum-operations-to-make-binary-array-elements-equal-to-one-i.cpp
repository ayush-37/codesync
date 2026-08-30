class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sw = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 1)continue;
            for(int j = 0; j < 3; j++){
                if(i + j >= n)return -1;
                if(nums[i+j] == 0)nums[i+j] = 1;
                else nums[i+j] = 0;
            }
            sw++;
        }
        return sw;
    }
};