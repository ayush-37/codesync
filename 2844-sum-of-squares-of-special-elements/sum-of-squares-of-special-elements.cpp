class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int tot = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(n%(i+1) == 0)tot += (nums[i]*nums[i]);
        }

        return tot;
    }
};