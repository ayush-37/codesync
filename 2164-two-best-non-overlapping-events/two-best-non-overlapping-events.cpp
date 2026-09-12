class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> dp(n,0);
        dp[n-1] = events[n-1][2];
        for(int i = n-2; i >= 0; i--){
            dp[i] = max(events[i][2], dp[i+1]);
        }

        auto find = [&](int last){
            int s = 0, e = n-1;
            int mid;
            while(s <= e){
                mid = s + (e-s)/2;
                if(events[mid][0] <= last)s = mid+1;
                else e = mid-1;
            }
            return s;
        };

        int ans = 0;
        for(int i = 0; i < n; i++){
            int nxt = find(events[i][1]);
            int sum = events[i][2] + ((nxt >= 0 && nxt < n) && (events[i][1] < events[nxt][0]) ? dp[nxt]: 0);
            ans = max(ans, sum);
        }

        return ans;
    }
};