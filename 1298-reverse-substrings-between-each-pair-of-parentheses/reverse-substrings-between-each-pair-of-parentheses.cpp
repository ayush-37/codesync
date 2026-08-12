class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> s1;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                queue<char> q;
                while(!s1.empty() && s1.top() != '('){
                    char c = s1.top();
                    s1.pop();
                    q.push(c);
                }
                s1.pop();
                while(!q.empty()){
                    char c = q.front();
                    q.pop();
                    s1.push(c);
                }
            }
            else s1.push(s[i]);
        }

        string ans = "";
        while(!s1.empty()){
            char c = s1.top();
            s1.pop();
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};