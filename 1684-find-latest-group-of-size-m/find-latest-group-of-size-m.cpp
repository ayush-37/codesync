class Solution {
public:
    struct DisjointSet{
        int n;
        vector<int> par, size;
        DisjointSet(int x){
            n = x;
            par.resize(n+1,0);
            size.resize(n+1,1);
            for(int i = 0; i <= n; i++)par[i] = i;
        }

        int findUpar(int x){
            if(par[x] == x)return x;
            else return par[x] = findUpar(par[x]);
        }

        void unite(int a, int b){
            int pa = findUpar(a);
            int pb = findUpar(b);
            
            if(pa == pb)return;

            if(size[pa] >= size[pb]){
                par[pb] = pa;
                size[pa] += size[pb];
            }
            else{
                par[pa] = pb;
                size[pb] += size[pa];
            }
        }

        int getSize(int a){
            int pa = findUpar(a);
            return size[pa];
        }
    };

    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        DisjointSet du(n);

        vector<int> sz(n+2,0), active(n+2,0);
        vector<int> ans(n+2,-1);
        for(int i = 0; i < n; i++){
            int x = arr[i];
            if(active[x-1] == 1 && active[x+1] == 1){
                int sza = du.getSize(x-1);
                int szb = du.getSize(x+1);
                sz[sza]--;
                sz[szb]--;

                if(sz[sza] == 0)ans[sza] = i;
                if(sz[szb] == 0)ans[szb] = i;

                du.unite(x-1,x+1);
                du.unite(x-1,x);
                int szx = du.getSize(x);
                sz[szx]++;
            }
            else if(active[x+1] == 1){
                int szb = du.getSize(x+1);
                sz[szb]--;

                if(sz[szb] == 0)ans[szb] = i;

                du.unite(x+1,x);
                int szx = du.getSize(x);
                sz[szx]++;
            }
            else if(active[x-1] == 1){
                int sza = du.getSize(x-1);
                sz[sza]--;

                if(sz[sza] == 0)ans[sza] = i;

                du.unite(x-1,x);
                int szx = du.getSize(x);
                sz[szx]++;
            }
            else{
                du.unite(x,x);
                sz[1]++;
                ans[1]++;
            }
            active[arr[i]] = 1;
        }

        if(sz[m] != 0)return n;
        else{
            return ans[m];
        }
    }
};