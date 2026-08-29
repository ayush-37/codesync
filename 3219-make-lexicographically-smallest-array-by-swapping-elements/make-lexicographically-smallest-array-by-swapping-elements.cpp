class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> p;
        for(int i = 0; i < n; i++)p.push_back({nums[i],i});
        sort(p.begin(),p.end());
        int i = 0, back = p[0].first;
        multiset<int> st;
        set<int> ind;
        vector<int> res(nums.begin(),nums.end());

        while(i < n){
            // cout<<p[i].second<<" ";
            if(p[i].first - back > limit){
                while(!st.empty()){
                    int j = *ind.rbegin();
                    int k = *st.rbegin();
                    res[j] = k;
                    ind.erase(prev(ind.end()));
                    st.erase(prev(st.end()));
                }
            }
            ind.insert(p[i].second);
            st.insert(p[i].first);

            back = p[i].first;
            i++;
        }
        while(!st.empty()){
            int j = *ind.rbegin();
            int k = *st.rbegin();
            res[j] = k;
            ind.erase(prev(ind.end()));
            st.erase(prev(st.end()));
        }
        return res;
    }
};