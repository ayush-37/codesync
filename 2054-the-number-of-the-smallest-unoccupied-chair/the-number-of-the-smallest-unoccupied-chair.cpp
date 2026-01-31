class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        unordered_map<string,int> mp;
        priority_queue<int,vector<int>,greater<int>> avail;
        for(int i = 0; i < n; i++){
            string s1 = to_string(times[i][0]);
            string s2 = to_string(times[i][1]);
            string str = s1 + "_" + s2;
            mp[str] = i;
            avail.push(i);
        }

        sort(times.begin(),times.end());
        vector<int> ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> dq;  // leav, chair

        for(int i = 0; i < n; i++){
            string s1 = to_string(times[i][0]);
            string s2 = to_string(times[i][1]);
            string str = s1 + "_" + s2;
            
            while(!dq.empty() && times[i][0] >= dq.top().first){
                int cha = dq.top().second;
                dq.pop();
                avail.push(cha);
            }

            int cha = avail.top();
            avail.pop();
            dq.push({times[i][1],cha});
            ans[mp[str]] = cha;
            if(mp[str] == targetFriend)return cha;
        }
        return ans[targetFriend];
    }
};