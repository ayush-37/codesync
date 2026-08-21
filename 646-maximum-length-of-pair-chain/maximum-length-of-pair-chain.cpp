class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n,1);
        vector<pair<int,int>> p;
        for(auto x: pairs){
            p.push_back({x[0],x[1]});
        }

        sort(p.begin(),p.end());

        for(int i = 1; i < p.size(); i++){
            for(int j = 0; j < i; j++){
                if(p[j].second < p[i].first)dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return dp[n-1];
    }
};