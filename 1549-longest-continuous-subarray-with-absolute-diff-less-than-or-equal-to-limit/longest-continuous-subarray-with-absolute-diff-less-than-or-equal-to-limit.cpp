class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, r = 0;
        multiset<int> st;
        int ans = 0;
        while(r < nums.size()){
            st.insert(nums[r]);
            while(l < r && (*st.rbegin() - *st.begin() > limit)){
                st.erase(st.find(nums[l]));
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};