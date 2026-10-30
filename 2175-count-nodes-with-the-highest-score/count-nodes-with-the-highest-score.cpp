class Solution {
public:
    vector<vector<int>> adj;
    int n;
    vector<int> child;
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        adj.assign(n,{});
        child.assign(n,0);

        for(int i = 1; i < n; i++){
            int p = parents[i];
            adj[p].push_back(i);
        }

        int temp = dfs(0);
        long long maxi = LLONG_MIN;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int lc = -1, rc = -1, l = 0, r = 0;
            if(adj[i].size() > 0){
                lc = adj[i][0];
                l = child[lc];
            }

            if(adj[i].size() > 1){
                rc = adj[i][1];
                r = child[rc];
            }

            long long prod = n - (l + r + 1);
            if(prod == 0)prod = 1LL;
            if(l != 0)prod *= (1LL*l);
            if(r != 0)prod *= (1LL*r);

            if(prod > maxi){
                maxi = prod;
                ans = 1;
            }
            else if(prod == maxi){
                ans++;
            }
        }

        return ans;
    }

    int dfs(int node){
        int c = 1;
        for(int nbr: adj[node]){
            c += dfs(nbr);
        }

        return child[node] = c;
    }
};