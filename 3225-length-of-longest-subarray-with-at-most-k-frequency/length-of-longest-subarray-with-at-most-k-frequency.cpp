class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int l = 0, r = 0, ans = 0;
        while(r < n){
            if(mp.find(nums[r]) != mp.end()){
                if(mp[nums[r]] < k)mp[nums[r]]++;
                else{
                    while(l < r && mp[nums[r]] == k){
                        mp[nums[l]]--;
                        l++;
                    }
                    mp[nums[r]]++;
                }
            }
            else{
                mp[nums[r]]++;
            }
            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};