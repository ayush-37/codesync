class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto x: asteroids){
            if(!st.empty() && (st.top() < 0 || x > 0)){
                st.push(x);
                continue;
            }

            while(!st.empty()){
                if(st.top() > 0 && x < 0 && st.top() < abs(x))st.pop();
                else break;
            }

            if(st.empty())st.push(x);
            else{
                if(st.top() == abs(x))st.pop();
                else if(st.top() < 0 && x < 0)st.push(x);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};