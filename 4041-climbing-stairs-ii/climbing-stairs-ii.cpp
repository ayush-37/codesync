class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> ans(n+1,0);
        ans[0] = 0;
        ans[1] = costs[0] + 1;
        if(n >= 2)ans[2] = costs[1] + min(ans[1] + 1, ans[0] + 4);

        for(int i = 3; i <= n; i++){
            ans[i] = costs[i-1] + min({ans[i-1] + 1, ans[i-2] + 4, ans[i-3] + 9});
        }

        return ans[n];
    }
};