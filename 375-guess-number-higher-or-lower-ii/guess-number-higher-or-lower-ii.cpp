class Solution {
public:
    vector<vector<int>> memo;
    int getMoneyAmount(int n) {
        if(n == 1)return 0;

        memo.resize(n+1,vector<int>(n+1,-1));

        int ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            ans = min(ans, i + max(solve(1,i-1) , solve(i+1,n)));
        }
        return ans;
    }
    int solve(int s, int e){
        if(s >= e) return 0;

        if(memo[s][e] != -1)return memo[s][e];

        int ans = INT_MAX;
        for(int i = s; i <= e; i++){
            ans = min(ans, i + max(solve(s,i-1), solve(i+1,e)));
        }
        return memo[s][e] = ans;
    }
};