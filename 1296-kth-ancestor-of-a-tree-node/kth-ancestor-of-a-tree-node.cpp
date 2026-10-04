class TreeAncestor {
public:
    vector<vector<int>> par;
    int jump;
    TreeAncestor(int n, vector<int>& parent) {
        int m = log2(n);
        jump = m;
        par.assign(n,vector<int>(m+1,-1));
        for(int i = 0; i < n; i++){
            par[i][0] = parent[i];
        }

        for(int j = 1; j <= m; j++){
            for(int i = 0; i < n; i++){
                if(par[i][j-1] == -1)continue;
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i <= jump; i++){
            if((k & (1<<i)))node = par[node][i];
            if(node == -1)break;
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */