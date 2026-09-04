class Solution {
public:
    struct DisjointSet{
        int n;
        vector<int> par, size;
        DisjointSet(int n){
            this->n = n;
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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet du(n);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(similar(strs[i], strs[j])){
                    du.unite(i,j);
                }
            }
        }

        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(du.findPar(i));
        }

        return (int)st.size();
    }

    bool similar(string a, string b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++)if(a[i] != b[i])diff++;
        if(diff == 0 || diff == 2)return true;
        else return false;
    }
};