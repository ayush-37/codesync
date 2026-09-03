class Solution {
public:
struct DisjointSet{
        int n;
        vector<int> par, size;
        DisjointSet(int x){
            n = x;
            par.resize(n,1);
            size.resize(n,1);

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
                par[pb] = pa;
                size[pa] += size[pb];
            }
            else{
                par[pa] = pb;
                size[pb] += size[pa];
            }
        }
    };
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return true;
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if(mn == 1)return false;

        vector<int> fact(mx+1,-1); // i is a prime factor of nums[fact[i]]
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

        int root = du.findPar(0);
        for(int i = 0; i < n; i++){
            if(du.findPar(i) != root)return false;
        }

        return true;
    }
};