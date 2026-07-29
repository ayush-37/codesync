class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size(), curr_big = nums[0], biggest = nums[0];
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] < curr_big){
                ans = i+1;
                curr_big = biggest;
            }
            else{
                biggest = max(biggest,nums[i]);
            }
        }
        return ans;
    }
};