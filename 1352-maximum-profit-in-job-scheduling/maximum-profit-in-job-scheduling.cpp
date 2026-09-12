class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int,int,int>> vp;
        for(int i = 0; i < n; i++)vp.push_back({startTime[i], endTime[i], profit[i]});
        sort(vp.begin(), vp.end());

        vector<int> nxt(n,n);
        for(int i = 0; i < n; i++){
            int s = 0, e = n-1;
            int mid, idx = n;
            while(s <= e){
                mid = s + (e-s)/2;
                if(get<1>(vp[i]) <= get<0>(vp[mid])){
                    idx = mid;
                    e = mid-1;
                }
                else s = mid+1;
            }
            nxt[i] = idx;
        }

        vector<int> dp(n+1,-1);
        return solve(0, vp, dp, nxt);
    }

    int solve(int i, vector<tuple<int,int,int>>& profit, vector<int>& dp, vector<int>& nxt){
        if(i == profit.size())return 0;
        if(dp[i] != -1)return dp[i];

        int skip = solve(i+1,profit, dp, nxt);
        int take = get<2>(profit[i]) + solve(nxt[i], profit, dp, nxt);

        return dp[i] = max(skip, take);
    }
};