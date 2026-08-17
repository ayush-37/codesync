class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2,vector<int>(k+1,0)), next(2,vector<int>(k+1,0));
        for(int ind = n-1; ind >= 0; ind--){
            for(int isHolding = 0; isHolding <= 1; isHolding++){
                for(int cap = 1; cap <= k; cap++){
                    if(isHolding == 0){
                        // can buy
                        curr[0][cap] = max(0+next[0][cap], -prices[ind] + next[1][cap]);
                    }
                    else{
                        // can sell
                        curr[1][cap] = max(0+next[1][cap], prices[ind] + next[0][cap-1]);
                    }
                }
            }
            next = curr;
        }

        return curr[0][k];
    }
};