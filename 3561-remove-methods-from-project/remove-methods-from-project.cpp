class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(auto x: invocations){
            graph[x[0]].push_back(x[1]);
        }

        vector<int> malicious(n,0);
        queue<int> q;
        q.push(k);
        malicious[k] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nbr: graph[node]){
                if(malicious[nbr] == 0){
                    q.push(nbr);
                    malicious[nbr] = 1;
                }
            }
        }

        bool canRemove = true;
        for(int i = 0; i < n && canRemove; i++){
            if(i == k)continue;

            if(malicious[i] == 0){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto nbr: graph[node]){
                        if(malicious[nbr] == 1){
                            canRemove = false;
                            q.push(nbr);
                            malicious[nbr] = 0;
                        }
                    }
                }
            }
        }

        vector<int> ans;
        if(canRemove){
            for(int i = 0; i < n; i++){
                if(malicious[i] == 0 )ans.push_back(i);
            }
        }
        else{
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
        }

        return ans;

    }

};