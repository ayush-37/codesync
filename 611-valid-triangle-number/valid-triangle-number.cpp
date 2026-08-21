class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int k = 2; k < nums.size(); k++){
            int longest = nums[k];
            int i = 0, j = k-1;
            while(i < j){
                if(nums[i] + nums[j] > longest){
                    ans += (j-i);
                    j--;
                }
                else i++;    
            }
        }
        return ans;
    }
};