class Solution {
public:
    vector<vector<int>> par;
    vector<int> dis;
    const int MOD = 1e9+7;
    int nodes, jumps;
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        nodes = edges.size()+1;
        jumps = log2(nodes) + 1;
        vector<vector<int>> graph(nodes);
        for(auto x: edges){
            int u = x[0]-1, v = x[1]-1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        par.assign(nodes,vector<int>(jumps,-1));

        dis.assign(nodes,0);
        vector<int> vis(nodes,0);
        int lev = 0;
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();

                dis[node] = lev;
                for(auto nbr: graph[node]){
                    if(vis[nbr] == 0){
                        vis[nbr] = 1;
                        q.push(nbr);
                        par[nbr][0] = node;
                    }
                }
            }
            lev++;
        }

        for(int j = 1; j < jumps; j++){
            for(int i = 0; i < nodes; i++){
                if(par[i][j-1] != -1){
                    par[i][j] = par[par[i][j-1]][j-1];
                }
            }
        }
        
        int qn = queries.size();
        vector<int> ans;
        for(auto q: queries){
            int node1 = q[0]-1, node2 = q[1]-1;
            int node = findLca(node1, node2);
            long long len = dis[node1] + dis[node2] - 2 * dis[node];
            if(len == 0)ans.push_back(0);
            else ans.push_back((int)modPower(1LL*2,len-1));
        }

        return ans;
    }

    long long modPower(long long a, long long b){
        long long res = 1;
        while(b){
            if(b&1)res = (res*a)%MOD;
            a= (a*a)%MOD;
            b/=2;
        }
        return res%MOD;
    }

    int findLca(int n1, int n2) {
        if(dis[n2] > dis[n1]) swap(n1, n2);

        int diff = dis[n1] - dis[n2];

        for(int i = 0; i < jumps; i++) {
            if(diff & (1 << i)) {
                n1 = par[n1][i];
            }
        }

        if(n1 == n2)return n1;

        for(int i = jumps - 1; i >= 0; i--) {
            if(par[n1][i] == -1)continue;
            if(par[n1][i] != par[n2][i]) {
                n1 = par[n1][i];
                n2 = par[n2][i];
            }
        }

        return par[n1][0];
    }
};