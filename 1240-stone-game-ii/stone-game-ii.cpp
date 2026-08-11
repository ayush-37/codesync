class Solution {
public:
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suff(n,0);
        vector<vector<int>> memo(n,vector<int>(n,-1));
        suff[n-1] = piles[n-1];
        for(int i = n-2;i >= 0; i--)suff[i] = suff[i+1]+piles[i];

        int ans = solve(0,n,1,suff,memo);
        return ans;
    }
    int solve(int curr,int n, int m, vector<int>& suff,vector<vector<int>>& memo){
        if(curr + 2*m >= n)return suff[curr];
        if(memo[curr][m] != -1)return memo[curr][m];

        int mini = INT_MAX;
        for(int i = 1; i <= 2*m; i++){
            int newInd = curr+i;
            int newM = max(i,m);
            mini = min(mini, solve(newInd, n, newM, suff,memo));
        }

        return memo[curr][m] = suff[curr]-mini;
    }
};