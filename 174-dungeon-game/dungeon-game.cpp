class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        if(dungeon[n-1][m-1] < 0)dp[n-1][m-1] = dungeon[n-1][m-1];
        else dp[n-1][m-1] = 1;

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1)continue;
                int t1 = INT_MIN,t2 = INT_MIN, t3 = INT_MIN;
                if(i+1 < n)t1 = min(dungeon[i][j],dp[i+1][j] + dungeon[i][j]);
                if(j+1 < m)t2 = min(dungeon[i][j],dp[i][j+1] + dungeon[i][j]);
                t3 = max(t1,t2);

                if(t3 < 0)dp[i][j] = t3;
                else dp[i][j] = 0;
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++)cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }

        
        return dp[0][0] >= 0? 1: 1-dp[0][0];
    }
};