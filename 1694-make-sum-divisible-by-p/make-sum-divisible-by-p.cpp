class Solution {
    using ll = long long;
public:
    int minSubarray(vector<int>& nums, int p) {
        ll sum = 0;
        for(int i = 0; i < nums.size(); i++)sum += nums[i];
        if(sum < p)return -1;
        else if(sum % p == 0)return 0;

        int target = sum%p; // the rem of sum of subarray that would have to be removed

        sum = 0;
        int ans = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;

        /*
        At each index i, we will check if there was a previous prefix remainder that makes the subarray removable.

        If the needed remainder is 0, that means the subarray starts at the very beginning (index 0).
        */

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem = sum%p;
            int need = (rem - target + p)%p;
            if(mp.count(need)){
                ans = min(ans,i-mp[need]);
            }
            mp[rem] = i;
        }
        if(ans == nums.size())return -1;
        else return ans;
    }
};