class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0, n = stones.size();
        for(auto x: stones)sum += x;
        vector<int> dp(sum+1,0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = sum; j >= stones[i]; j--){
                dp[j] = dp[j] | dp[j-stones[i]];
            }
        }

        for(int i = sum/2; i >= 0; i--){
            if(dp[i])return sum - 2*i;
        }
        return 0;

    }
};