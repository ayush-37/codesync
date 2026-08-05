class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<int> take(n,0);

        stack<char> st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                if(s[i] != ')'){
                    take[i] = 1;
                    if(s[i] == '(')st.push(s[i]);
                }
            }
            else{
                if(s[i] == ')'){
                    st.pop();
                    take[i] = 1;
                }else{
                    take[i] = 1;
                    if(s[i] == '(')st.push(s[i]);
                }
            }
        }

        string ans = "";
        int cnt = 0, flag = st.size();
        for(int i = n-1; i >= 0; i--){
            if(take[i] == 0)continue;
            else{
                if(s[i] == '(' && cnt < flag){
                    cnt++;
                    continue;
                }
                else{
                    ans.push_back(s[i]);
                }
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};