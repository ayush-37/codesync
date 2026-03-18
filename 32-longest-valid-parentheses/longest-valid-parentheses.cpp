class Solution {
public:
    int longestValidParentheses(string s) {
        int cntOpen = 0, cntClose = 0;
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')cntOpen++;
            else cntClose++;

            if(cntOpen == cntClose)ans = max(ans, cntOpen+cntClose);

            if(cntClose > cntOpen){
                cntOpen = 0;
                cntClose = 0;
            }
        }
        cntOpen = 0, cntClose = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '(')cntOpen++;
            else cntClose++;

            if(cntOpen == cntClose)ans = max(ans, cntOpen+cntClose);

            if(cntOpen > cntClose){
                cntOpen = 0;
                cntClose = 0;
            }
        }
        return ans;
    }
};


/*
“I use a two-pass linear scan. In the first pass, I track open and close brackets and reset when closing exceeds opening. This catches invalid prefixes.
In the second pass, I reverse the scan to handle extra opening brackets. This ensures all valid substrings are considered.”


*/