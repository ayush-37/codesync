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
            int pa = findPar(a), pb = findPar(b);
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
    };
    bool gcdSort(vector<int>& nums) {
        int n = nums.size(), m = *max_element(nums.begin(), nums.end());
        vector<int> mul(m+1,-1);

        DisjointSet du(n);

        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int p = 2; p*p <= nums[i]; p++){
                if(num % p == 0){
                    if(mul[p] != -1)du.unite(mul[p], i);
                    else{
                        mul[p] = i;
                    }

                    while(num % p == 0)num /= p;
                }
            }
            if(num > 1){
                if(mul[num] != -1)du.unite(mul[num], i);
                else{
                    mul[num] = i;
                }
            }
        }

        unordered_map<int,vector<int>> seg;
        unordered_map<int,multiset<int>> seg_num;
        for(int i = 0; i < n; i++){
            int pa = du.findPar(i);
            seg[pa].push_back(i);
            seg_num[pa].insert(nums[i]);
        }

        vector<int> ans = nums;
        for(int i = 0; i < n; i++){
            if(seg[i].empty())continue;

            int j = 0;
            // cout<<i<<" -- ";
            for(auto itr = seg_num[i].begin(); itr != seg_num[i].end(); itr++){
                // cout<<seg[i][j]<<" ";
                ans[seg[i][j]] = *itr;
                j++;
            }
            // for(auto x: ans)cout<<x<<" ";
            // cout<<endl;
        }
        

        for(int i = 1; i < n; i++)if(ans[i] < ans[i-1])return false;
        return true;
    }
};