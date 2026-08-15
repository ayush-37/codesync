class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.back() == 0)return 0;
        int cnt = 0, n = nums.size();
        for(auto x: nums)cnt ^= x;
        if(cnt != 0)return n;
        else return n-1;
    }
};