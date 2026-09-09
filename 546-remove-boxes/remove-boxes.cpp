class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int removeBoxes(vector<int>& boxes) {
        n = boxes.size(); 
        if(n == 0 || n == 1)return n;

        dp.resize(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(0,n-1,0,boxes);
    }

    int solve(int l, int r, int s, vector<int>& boxes){
        if(l > r)return 0;
        if(l == r)return dp[l][r][s] = (s+1)*(s+1);

        if(dp[l][r][s] != -1)return dp[l][r][s];

        int maxi = (s+1)*(s+1) + solve(l+1, r, 0, boxes);
        for(int i = l+1; i <= r; i++){
            if(boxes[l] == boxes[i])maxi = max(maxi, solve(l+1,i-1, 0, boxes) + solve(i, r, s+1, boxes));
        }

        return dp[l][r][s] = maxi;
    }
};