class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = 0, n = costs.size();
        for(int i = 0; i < n; i++)maxi = max(maxi,costs[i]);
        vector<int> v(maxi+1, 0);
        for(auto x: costs)v[x]++;

        int ans = 0;
        for(int i = 1; i <= maxi; i++){
            int can = min(v[i],coins/i);
            ans += can;
            coins -= i*can;
            if(coins == 0)break;
        }
        return ans;
    }
};