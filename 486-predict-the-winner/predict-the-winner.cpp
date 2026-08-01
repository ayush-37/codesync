class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        bool case1 = (nums[i] - solve(nums,i+1,j)) >= 0;
        bool case2 = (nums[j] - solve(nums,i,j-1)) >= 0;

        return case1|case2;

    }

    int solve(vector<int>& nums, int i, int j){
        if(i > j)return 0;

        int c1 = nums[i] - solve(nums,i+1,j);
        int c2 = nums[j] - solve(nums,i,j-1);
        return max(c1,c2);
    }
};