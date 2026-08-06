class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        int pro = solve(prices,0,1,dp);
        return pro;
    }

    int solve(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp){
        if(ind >= (int)prices.size())return 0;

        if(dp[ind][buy] != -1)return dp[ind][buy];
        
        int pro = 0;
        if(buy){
            int bought = -prices[ind] + solve(prices,ind+1,0,dp);
            int notBought = solve(prices,ind+1,1,dp);
            pro = max(bought,notBought);
        }
        else{
            int sell = prices[ind] + solve(prices,ind+2,1,dp);
            int notSell = solve(prices,ind+1,0,dp);
            pro = max(sell,notSell);
        }

        return dp[ind][buy] = pro;
    }
};