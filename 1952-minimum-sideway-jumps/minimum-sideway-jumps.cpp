class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,INT_MAX));
        return solve(obstacles,2,0,dp);
    }
    int solve(vector<int>& obstacles, int curr, int pos,vector<vector<int>>& dp){
        if(pos == (int)obstacles.size()-1)return dp[curr][pos] = 0;

        if(dp[curr][pos] != INT_MAX)
        return dp[curr][pos];

        if(obstacles[pos+1] != curr)return dp[curr][pos] = solve(obstacles,curr,pos+1,dp);
        else{
            int ans = INT_MAX;
            for(int i = 1; i < 4; i++){
                // the lane on which frog is jumping
                if(i != curr && obstacles[pos] != i){
                    ans = min(ans,solve(obstacles,i,pos,dp)+1);
                }
            }
            return dp[curr][pos] = ans;
        }
    }
};