class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty() || st.top() != mp[s[i]])return false;
                else st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};