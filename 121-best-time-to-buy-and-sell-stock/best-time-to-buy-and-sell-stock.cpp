class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size()-1;
        int maxi = 0,ans = 0;
        while(n >= 0){
            if(prices[n] >= maxi)maxi = prices[n];
            else ans = max(ans,maxi-prices[n]);
            n--;
        }
        return ans;
    }
};