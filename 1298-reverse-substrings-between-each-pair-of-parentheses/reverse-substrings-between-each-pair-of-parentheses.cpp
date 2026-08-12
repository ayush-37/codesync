class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pair(n,0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        int dir = 1;
        string ans = "";
        for(int i = 0; i < n; i+=dir){
            if(s[i] == '(' || s[i] == ')'){
                i = pair[i];
                dir = -dir;
            }
            else ans += s[i];
        }

        return ans;
    }
};