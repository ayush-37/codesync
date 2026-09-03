class Solution {
public:
    struct DisjointSet{
        int n;
        vector<int> par, size;
        DisjointSet(int x){
            n = x;
            par.resize(x, 1);
            size.resize(x, 1);
            for(int i = 0; i < n; i++)par[i] = i;
        }

        int findPar(int x){
            if(par[x] == x)return x;
            else return par[x] = findPar(par[x]);
        }

        void unite(int a, int b){
            int pa = findPar(a);
            int pb = findPar(b);

            if(pa == pb)return;

            if(size[pa] >= size[pb]){
                size[pa] += size[pb];
                par[pb] = pa;
            }
            else{
                size[pb] += size[pa];
                par[pa] = pb;
            }
        }

        int getSize(int x){
            int px = findPar(x);
            return size[px];
        }
    };
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<int> fact(m+1,-1);
        DisjointSet du(n);

        for(int i = 0; i < n; i++){
            int x = nums[i];
            for(int p = 2; p*p <= x; p++){
                if(x%p != 0)continue;

                if(fact[p] != -1)du.unite(fact[p], i);
                else fact[p] = i;

                while(x%p == 0)x /= p;
            }

            if(x > 1){
                if(fact[x] != -1)du.unite(fact[x], i);
                else fact[x] = i;
            }
        }

        int ans = 1;
        for(int i = 0; i < n; i++){
            ans = max(ans,du.getSize(i));
        }

        return ans;
    }
};