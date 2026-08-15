class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = solve(prices,0,1,dp,fee);
        return ans;
    }

    int solve(vector<int>& p, int i, int buy, vector<vector<int>>& dp, int& fee){
        if(i >= p.size())return 0;
        if(dp[i][buy] != -1)return dp[i][buy];

        int pro = 0;
        if(buy){
            pro = max(-p[i] + solve(p,i+1,0,dp,fee), solve(p,i+1,1,dp,fee));
        }
        else{
            pro = max(p[i] - fee + solve(p,i+1,1,dp,fee), solve(p,i+1,0,dp,fee));
        }

        return dp[i][buy] = pro;
    }
};