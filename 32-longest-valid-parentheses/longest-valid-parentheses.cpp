class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = 2;
                    if(i-2 >= 0)dp[i] += dp[i-2];
                }
                else{
                    int ind = i - dp[i-1] - 1;
                    if(ind >= 0 && s[ind] == '('){
                        dp[i] = 2 + dp[i-1];
                        if(ind-1 >= 0) dp[i] += dp[ind-1];
                    }
                }
            }

            ans = max(ans,dp[i]);
        }

        return ans;
    }
};

/*
⏱️ Complexity

Time: O(n)

Space: O(n)

🧠 Interview Explanation (clean version)

“I define dp[i] as the longest valid substring ending at i.
If I see ‘()’, I extend by 2.
If I see ‘))’, I check if I can match it with a previous ‘(’ by jumping back using dp[i-1].
This allows me to build solutions incrementally in O(n).”



*/