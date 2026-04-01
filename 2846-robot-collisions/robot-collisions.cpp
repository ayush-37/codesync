class Solution {
public:
struct state{
    int pos,hea,ind;
    char dir;
};
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<state> v(n);
        for(int i = 0; i < n; i++){
            v[i] = {positions[i],healths[i],i,directions[i]};
        }

        sort(v.begin(),v.end(),[] (const state& a, const state& b){
            return a.pos < b.pos;
        });

        stack<state> st;
        for(int i = 0; i < n; i++){
            state curr = v[i];
            if(curr.dir == 'R')st.push(curr);
            else{
                while(!st.empty() && st.top().dir == 'R' && curr.hea > 0){
                    state prev = st.top();
                    st.pop();
                    if(prev.hea == curr.hea){
                        curr.hea = 0;
                        prev.hea = 0;
                    }
                    else if(prev.hea < curr.hea){
                        prev.hea = 0;
                        curr.hea -= 1;
                    }
                    else{
                        prev.hea -= 1;
                        curr.hea = 0;
                        st.push(prev);
                    }
                }
                if(curr.hea > 0)st.push(curr);
            }
        }

        vector<state> temp;

        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        sort(temp.begin(),temp.end(),[] (const state& a, const state& b){
            return a.ind < b.ind;
        });
        vector<int> ans;
        for(auto x: temp){
            ans.push_back(x.hea);
        }
        return ans;
    }
};