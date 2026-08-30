class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> taken(n,0);
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;

            taken[i] = 1;
            ans += solve(1, nums[i], nums, taken);
            taken[i] = 0;
        }
        return ans;
    }

    int solve(int i, int last, vector<int>& nums, vector<int>& taken){
        if(i == taken.size())return 1;
        
        int tot = 0;
        for(int j = 0; j < nums.size(); j++){
            if(taken[j])continue;
            if (j > 0 && nums[j] == nums[j - 1] && !taken[j - 1])continue;

            int sq = sqrt(nums[j] + last);
            if(sq*sq == nums[j] + last){
                taken[j] = 1;
                tot += solve(i+1, nums[j], nums, taken);
                taken[j] = 0;
            }
        }
        return tot;
    }
};