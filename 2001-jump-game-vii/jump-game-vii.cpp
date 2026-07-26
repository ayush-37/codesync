class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<long long> dp(n,0);
        dp[0] = 1;
        long long cnt = 0;
        for(int i = 1; i < n; i++){
            if(i-minJump >= 0)cnt+=dp[i-minJump];
            if(i-maxJump-1 >= 0)cnt -= dp[i-maxJump-1];

            if(s[i] == '0' && cnt > 0)dp[i] = 1;
        }
        return dp[n-1];
    }
};