class Solution {
public:
    vector<int> nxt;
    vector<vector<int>> memo;
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        memo.assign(n,vector<int>(k+1,-1));
        nxt.assign(n,n);
        for(int i = 0; i < n; i++){
            int s = 0, e = n-1;
            int mid, idx = n;
            while(s <= e){
                mid = s + (e-s)/2;
                if(events[i][1] < events[mid][0]){
                    idx = mid;
                    e = mid-1;
                }
                else s = mid+1;
            }

            nxt[i] = idx;
        }
        return solve(0,k,events);
    }
    int solve(int i, int k, vector<vector<int>>& events){
        if(i == events.size() || k == 0)return 0;
        if(memo[i][k] != -1)return memo[i][k];

        int skip = solve(i+1,k,events);
        int take = events[i][2] + solve(nxt[i], k-1, events);

        return memo[i][k] = max(skip, take);
    }
};