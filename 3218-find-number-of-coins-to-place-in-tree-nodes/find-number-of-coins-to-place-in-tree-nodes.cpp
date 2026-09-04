class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    vector<long long> ans;
    set<int> st;
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        adj.resize(n);
        vis.resize(n,0);
        ans.resize(n,0);

        for(auto x: edges){
            int u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vis[0] = 1;
        vector<int> v = dfs(0,cost);
        return ans;
    }

    vector<int> dfs(int node, vector<int>& cost){
        vector<int> temp;
        add(cost[node], temp);
        for(auto nbr: adj[node]){
            if(vis[nbr] == 0){
                vis[nbr] = 1;
                vector<int> child = dfs(nbr,cost);

                for(auto x: child){
                    add(x, temp);
                }
            }
        }

        if(temp.size() < 3)ans[node] = 1LL;
        else{
            int n = temp.size();
            long long c1 = 1LL * temp[0] * temp[1] * temp[n-1];
            long long c2 = 1LL * temp[n-1] * temp[n-2] * temp[n-3];
            long long maxCoins = max(c1,c2);
            ans[node] = maxCoins > 0? maxCoins: 0;
        }
        return temp;
    }

    void add(int x, vector<int>& temp){
        temp.push_back(x);
        sort(temp.begin(), temp.end());
        if(temp.size() > 5){
            vector<int> v;
            v.push_back(temp[0]);
            v.push_back(temp[1]);
            int n = temp.size();
            v.push_back(temp[n-3]);
            v.push_back(temp[n-2]);
            v.push_back(temp[n-1]);
            temp = v;
        }

    }
};