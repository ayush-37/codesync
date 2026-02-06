class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> nums2(n);
        for(int i = 0; i < n; i++)nums2[i] = nums[i];
        sort(nums2.begin(),nums2.end());
        int ans = n-1;
        for(int i = 0; i < n; i++){
            int ind = upper_bound(nums2.begin(),nums2.end(),k*nums2[i]) - nums2.begin();
            if(ind == n)return min(ans,i);
            else{
                ans = min(ans,i + (n-ind)); 
            }
        }
        return ans;
    }
};