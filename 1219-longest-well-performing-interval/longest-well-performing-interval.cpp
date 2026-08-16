class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> pref(n+1,0);
        for(int i = 0; i < hours.size(); i++){
            if(hours[i] > 8)hours[i] = 1;
            else hours[i] = -1;

            pref[i+1] = pref[i] + hours[i];
        }

        stack<int> st; // to store indices with minimum soln

        for(int i = 0; i < n; i++){
            if(st.empty())st.push(i);
            else {
                if(pref[st.top()] > pref[i])st.push(i);
            }
        }

        int ans = 0;
        for(int r = n; r >= 0; r--){
            while(!st.empty() && pref[r] > pref[st.top()]){
                int l = st.top();
                st.pop();
                ans = max(ans,r-l);
            }
        }

        return ans;
        
    }
};