/*
Complexity
Time: O(n × digits) ≈ O(n)
Space: O(n)
*/

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(mp.count(nums[i]))ans = min(ans,abs(i-mp[nums[i]]));
            int temp = nums[i],sum = 0;
            while(temp){
                int r = temp%10;
                sum = sum*10 + r;
                temp /= 10;
            }
            mp[sum] = i;
        }

        if(ans == INT_MAX)return -1;
        else return ans;
    }
};