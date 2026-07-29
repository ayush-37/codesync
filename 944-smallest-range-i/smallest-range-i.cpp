class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end())-k;
        int mini = *min_element(nums.begin(),nums.end())+k;

        if(mini >= maxi)return 0;
        else return maxi-mini;
    }
};