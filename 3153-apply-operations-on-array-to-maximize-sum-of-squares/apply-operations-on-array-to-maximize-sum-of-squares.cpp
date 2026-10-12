class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(32,0);
        for(auto x: nums){
            for(int i = 0; i < 32; i++){
                if(x & (1LL<<i))cnt[i]++;
            }
        }

        const int MOD = 1e9+7;
        long long ans = 0;
        while(k--){
            long long x = 0;
            for(int i = 0; i < 32; i++){
                if(cnt[i] != 0){
                    x |= (1LL<<i);
                    cnt[i]--;
                }
            }

            ans = (ans + (x * x) % MOD) % MOD;
        }

        return ans;
    }
};