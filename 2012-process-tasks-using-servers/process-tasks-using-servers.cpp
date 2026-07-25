class Solution {
    using pii = pair<int,int>;
    using tiii = tuple<int,int,int>;
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pii,vector<pii>,greater<pii>> free;
        priority_queue<tiii,vector<tiii>,greater<tiii>> busy;
        queue<int> task;
        for(int i = 0; i < n; i++)free.push({servers[i],i});
        for(int i = 0; i < m; i++)task.push(tasks[i]);

        long long currTime = 0,cnt = 0;
        vector<int> ans;
        while(!task.empty()){
            // at time i which servers finishes their tasks
            currTime = max(currTime, (long long)cnt);
            while(!busy.empty() && get<0>(busy.top()) <= currTime){
                auto [fTime,wt,ind] = busy.top();
                busy.pop();
                free.push({wt,ind});
            }

            if(!free.empty()){
                int t = task.front();
                task.pop();
                auto [wt,ind] = free.top();
                free.pop();
                busy.push({currTime+t,wt,ind});
                ans.push_back(ind);
                cnt++;
            }
            else{
                currTime = get<0>(busy.top());
            }
            // currTime++;
        }
        return ans;
    }
};