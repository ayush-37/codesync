class Solution {
public:
    unordered_map<int, int> memo;
    bool predictTheWinner(vector<int>& nums) {
        // memo.clear();
        int n = nums.size();

        int c1 = nums[0] - solve(nums,1,n-1);
        int c2 = nums[n-1] - solve(nums,0,n-2);

        return (max(c1,c2) >= 0);
    }

    int solve(vector<int>& nums, int i, int j){
        if(i > j)return 0;
        if(memo.find(i*100 + j) != memo.end())return memo[i*100 + j];

        int c1 = nums[i] - solve(nums,i+1,j);
        int c2 = nums[j] - solve(nums,i,j-1);
        return memo[i*100 + j] = max(c1,c2);
    }
};