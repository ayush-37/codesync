class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        vector<int> psum0(n+1),psum1(n+1);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)psum0[i+1] = psum0[i]+1;
            else psum0[i+1] = psum0[i];
            if(nums[i] == 1)psum1[i+1] = psum1[i]+1;
            else psum1[i+1] = psum1[i];
        }

        int ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n+1; i++){
            if(mp.count(psum0[i] - psum1[i]))ans = max(ans,i - mp[psum0[i] - psum1[i]]);
            else mp[psum0[i]-psum1[i]] = i;
        }
        return ans;
    }
};