class Solution {
public:
    vector<vector<vector<int>>> dp;
    int nh, nc, t;
    int INF = 1e6+1;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        nh = m, nc = n, t = target;
        dp.resize(m, vector<vector<int>>(n+1, vector<int>(target+1,-1)));
        int ans = solve(0, 0, 0,houses, cost);
        return ans == INF? -1: ans;
    }

    int solve(int idx, int col, int nbr, vector<int>& houses, vector<vector<int>>& cost){
        if(idx == nh){
            return (nbr == t)? 0: INF;
        }
        if(nbr > t)return INF;

        if(dp[idx][col][nbr] != -1)return dp[idx][col][nbr];
        int minCost = INF;

        if(houses[idx] == 0){
            for(int i = 1; i <= nc; i++){
                int newNbr = nbr;
                if(col != i)newNbr++;
                minCost = min(minCost, cost[idx][i-1] + solve(idx+1, i, newNbr, houses, cost));
            }
        }
        else{
            int newNbr = nbr;
            if(houses[idx] != col)newNbr++;
            minCost = solve(idx+1, houses[idx], newNbr, houses, cost);
        }

        return dp[idx][col][nbr] = minCost;
    }
};