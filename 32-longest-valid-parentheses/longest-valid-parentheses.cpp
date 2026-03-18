class Solution {
public:
int solve(int i, string &s) {
    if(i >= s.size() || s[i] == ')') return 0;

        int balance = 0;

        for(int j = i; j < s.size(); j++){
            if(s[j] == '(') balance++;
            else balance--;

            if(balance == 0){
                return (j - i + 1) + solve(j + 1, s);
            }

            if(balance < 0) break;
        }

        return 0;
    }
    int longestValidParentheses(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++){
            ans = max(ans, solve(i, s));
        }
        return ans;
    }
};