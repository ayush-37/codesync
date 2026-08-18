class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> st;
        int res= 0;
        for(auto x: arr){
            while(!st.empty() && st.back() <= x){
                int y = st.back();
                st.pop_back();
                int temp = st.empty()?INT_MAX: st.back();
                res += y * min(x,temp);
            }
            st.push_back(x);
        }

        while(st.size() > 1){
            int x = st.back();
            st.pop_back();
            res += x*st.back();
        }
        return res;
    }
};