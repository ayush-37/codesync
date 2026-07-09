class Solution {
public:
    struct DisJointSet{
        vector<int> par,size;
        int n;

        DisJointSet(int n){
            this->n = n;
            par.resize(n,0);
            size.resize(n,1);
            for(int i = 0; i < n; i++)par[i] = i;
        }

        int findUPar(int x){
            if(par[x] == x)return x;
            return par[x] = findUPar(par[x]);
        }

        void unionBySize(int u, int v){
            int pu = findUPar(u);
            int pv = findUPar(v);

            if(pu == pv)return;

            if(size[pu] <= size[pv]){
                par[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                par[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        long long back = INT_MIN;
        int q = queries.size();
        DisJointSet du(n);

        for(int i = 0; i < n; i++){
            if(abs(back-nums[i]) <= maxDiff){
                du.unionBySize(i,i-1);
            }
            back = nums[i];
        }
        
        vector<bool> ans(q,false);
        for(int i = 0; i < q; i++){
            int u = queries[i][0], v = queries[i][1];
            if(du.findUPar(u) == du.findUPar(v))ans[i] = true;
        }
        return ans;
    }
};