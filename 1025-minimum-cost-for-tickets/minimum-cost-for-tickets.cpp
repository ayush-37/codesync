class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> ans(366);
        days.push_back(0);
        sort(days.begin(),days.end());
        for(int i = 1; i < days.size(); i++){
            int t1 = max(0,days[i]-1);
            int t2 = max(0,days[i]-7);
            int t3 = max(0,days[i]-30);

            t1 = upper_bound(days.begin(),days.end(),t1) - days.begin()-1;
            t2 = upper_bound(days.begin(),days.end(),t2) - days.begin()-1;
            t3 = upper_bound(days.begin(),days.end(),t3) - days.begin()-1;
            ans[days[i]] = min({ans[days[t1]]+costs[0],ans[days[t2]]+costs[1],ans[days[t3]]+costs[2]});
        }

        return ans[days.back()];
    }
};