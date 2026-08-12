class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int>psum(n+1,0);
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));

        for(int i = 1; i <= n; i++)psum[i] = psum[i-1] + stones[i-1];

        int tot = solve(1,n,psum,memo);
        return tot;
    }

    int solve(int s, int e, vector<int>& psum, vector<vector<int>>& memo){
        if(s == e)return 0;
        if(memo[s][e] != -1)return memo[s][e];
        int s1 = psum[e]-psum[s] - solve(s+1,e,psum,memo);
        int s2 = psum[e-1]-psum[s-1] - solve(s,e-1,psum,memo);
        return memo[s][e] = max(s1,s2);
    }
};