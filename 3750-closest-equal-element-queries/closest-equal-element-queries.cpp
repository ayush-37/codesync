class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // first prev next last
        int n = nums.size();
        vector<int> prev(n,-1),next(n,-1);

        unordered_map<int,int> mp;
        unordered_map<int,pair<int,int>> firstNlast;
        for(int i = 0; i < n; i++){
            if(mp.count(nums[i])){
                next[mp[nums[i]]] = i;
                prev[i] = mp[nums[i]];
                mp[nums[i]] = i;
            }
            else{
                mp[nums[i]] = i;
            }

            if(firstNlast.count(nums[i])){
                firstNlast[nums[i]].second = i;
            }
            else{
                firstNlast[nums[i]] = {i,i};
            }
        }

        vector<int> res;
        for(int i = 0; i < queries.size(); i++){
            int x = nums[queries[i]];
            if(firstNlast[x].first == firstNlast[x].second)res.push_back(-1);
            else{
                int ans = INT_MAX;
                if(next[queries[i]] == -1){
                    ans = min(ans, (int)nums.size()-queries[i]+firstNlast[x].first);
                }
                else{
                    ans = min(ans, next[queries[i]]-queries[i]);
                }
                if(prev[queries[i]] == -1){
                    ans = min(ans, (int)nums.size()+queries[i]-firstNlast[x].second);
                }
                else{
                    ans = min(ans, queries[i]-prev[queries[i]]);
                }

                if(ans == INT_MAX)res.push_back(-1);
                else res.push_back(ans);

            }
        }

        return res;
    }
};