class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size(), cnt = 0;
        for(int i = 0; i + m < n; i++){
            bool is = true;
            for(int j = 0; j < m; j++){
                if(pattern[j] == 1){
                    if(nums[i+j+1] <= nums[i+j]){
                        is = false;
                        break;
                    }
                }
                else if(pattern[j] == 0){
                    if(nums[i+j+1] != nums[i+j]){
                        is = false;
                        break;
                    }
                }
                else{
                    if(nums[i+j+1] >= nums[i+j]){
                        is = false;
                        break;
                    }
                }
            }
            if(is)cnt++;
        }
        return cnt;
    }
};