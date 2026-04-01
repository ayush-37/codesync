class Solution {
public:
struct state{
    int pos, hea;
    char dir;
};
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<state> v(n);
        unordered_map<int,state> mp;
        for(int i = 0; i < n; i++){
            v[i].pos = positions[i];
            v[i].hea = healths[i];
            v[i].dir = directions[i];

            mp[positions[i]] = v[i];
        }

        sort(v.begin(),v.end(),[](const state& a, const state& b){
            return a.pos < b.pos;
        });

        stack<state> st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(v[i]);
            }
            else{
                if(v[i].dir == 'R'){
                    st.push(v[i]);
                }
                else{
                    int h = v[i].hea, p = v[i].pos;
                    char d = v[i].dir;
                    while(!st.empty() && st.top().dir == 'R' && h > 0){
                        auto s = st.top();
                        st.pop();
                        if(s.hea == h){
                            mp.erase(s.pos);
                            mp.erase(p);
                            h = 0;
                        }
                        else if(s.hea < h){
                            mp.erase(s.pos);
                            h--;
                        }
                        else {
                            mp.erase(p);
                            s.hea -= 1;
                            mp[s.pos] = s;
                            st.push(s);
                            h = 0;
                        }
                    }
                    if(h > 0){
                        mp[p].hea = h;
                        st.push(mp[p]);
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(mp.count(positions[i]))ans.push_back(mp[positions[i]].hea);
        }
        return ans;
    }
};