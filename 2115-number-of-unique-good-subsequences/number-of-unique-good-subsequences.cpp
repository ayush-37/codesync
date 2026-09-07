class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size(), cnt0 = 0;
        const int MOD = 1e9+7;
        vector<long long> dp(n+1,0);
        vector<int> bin(2,-1);
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(binary[i-1] == '0')cnt0++;

            if(binary[i-1] == '0' && flag)continue;
            else if(binary[i-1] == '1' && flag){
                dp[i] = 1;
                bin[1] = i;
                flag = false;
            }
            else{
                int x = binary[i-1] - '0';
                dp[i] = (2*dp[i-1]) % MOD;
                if(bin[x] != -1)dp[i] = (dp[i] - dp[bin[x] - 1] + MOD)% MOD;
                bin[x] = i;
            }
        }
        return dp[n] + (cnt0 != 0);
    }
};