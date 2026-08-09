class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty())st.push({s[i],1});
            else{
                if(st.top().first == s[i]){
                    if(st.top().second+1 == k){
                        int t = k-1;
                        while(!st.empty() && t > 0){
                            st.pop();
                            t--;
                        }
                    }
                    else{
                        st.push({s[i],st.top().second+1});
                    }
                }
                else st.push({s[i],1});
            }
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};