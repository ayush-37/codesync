class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> st;
        for(int i = 0; i < k; i++)st.insert(i);
        vector<int> ans(k,0);

        int n = arrival.size();
        for(int i = 0; i < n; i++){
            int start = arrival[i], end = start + load[i];
            while(!pq.empty() && pq.top().first <= start){
                auto [x,y] = pq.top();
                pq.pop();
                st.insert(y);
            }
            if(st.empty())continue;
            int ind = (i%k);
            auto itr = st.lower_bound(ind);
            int x;
            if(itr == st.end()){
                x = *st.begin();
                st.erase(st.begin());
            }
            else{
                x = *itr;
                st.erase(itr);
            }
            pq.push({end, x});
            ans[x]++;
        }

        int maxi = *max_element(ans.begin(), ans.end());
        vector<int> res;
        for(int i = 0; i < k; i++){
            if(maxi == ans[i])res.push_back(i);
        }

        return res;
    }
};