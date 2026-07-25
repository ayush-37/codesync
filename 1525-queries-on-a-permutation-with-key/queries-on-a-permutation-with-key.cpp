class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v(m,0);
        for(int i = 0; i < m; i++){
            v[i] = i;
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int t = queries[i]-1;
            ans.push_back(v[t]);
            for(int j = 0; j < m; j++){
                if(v[j] < v[t])v[j]++;
            }
            v[t] = 0;
        }
        return ans;
    }
};