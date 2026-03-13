class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        for(int i = 0; i < n-2; i++){
            int l = i+1, r = n-1;
            while(l < r){
                int val = nums[i] + nums[l] + nums[r];
                if(abs(target-val) < abs(ans-target))ans = val;
                
                if(val == target)return target;
                else if(val < target)l++;
                else r--;
            }
        }
        return ans;

    }
};