class Solution {
public:
    int minInsertions(string s) {
        string temp = "";
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')temp.push_back(s[i]);
            else{
                if(i + 1 < s.size() && s[i+1] == ')'){
                    temp.push_back(s[i]);
                    i++;
                }
                else{
                    cnt++;
                    temp.push_back(s[i]);
                }
            }
        }

        stack<char> st;
        for(auto c: temp){
            if(c == ')'){
                if(st.empty())cnt++;
                else st.pop();
            }
            else{
                st.push(c);
            }
        }

        return cnt + ((int)st.size()) * 2;
    }
};