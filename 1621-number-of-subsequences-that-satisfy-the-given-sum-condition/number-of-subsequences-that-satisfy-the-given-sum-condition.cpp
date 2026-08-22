class Solution {
public:

    const long long MOD = 1e9 + 7;

    long long power(long long a, long long n) {
        long long ans = 1;

        while (n > 0) {
            if (n & 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            n >>= 1;
        }

        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l = 0, r = nums.size()-1;
        int ans = 0;
        while(l <= r){
            if(nums[l] + nums[r] > target)r--;
            else{
                int len = r-l;
                ans = (ans + power(2, len*1LL))%MOD;
                l++;
            }
        }
        return ans;
    }
};