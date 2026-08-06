class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26,0), lastInd(26,0);
        stack<char> st;
        int n = s.size();

        for(int i = 0; i < n; i++){
            lastInd[s[i]-'a'] = i;
        }

        for(int i = 0; i < n; i++){
            if(vis[s[i] -'a'] != 0)continue;
            
            while(!st.empty() && s[i] < st.top()){
                if(lastInd[st.top()-'a'] > i){
                    vis[st.top()-'a'] = 0;
                    st.pop();
                }
                else break;
            }
            st.push(s[i]);
            vis[s[i]-'a'] = 1;
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};