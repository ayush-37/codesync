class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<long long, int> mp;
        for(int i = 0; i < n; i++){
            long long s = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                s += (long long)wall[i][j];
                mp[s]++;
            }
        }

        int ans = n;
        for(auto [k,v]: mp)ans = min(ans, n-v);
        return ans;

    }
};