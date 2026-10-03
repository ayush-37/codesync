class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[i] > heights[st.top()]){
                ans[i]++;
                st.pop();
            }
            if(!st.empty())ans[i]++;
            st.push(i);
        }

        return ans;
    }
};