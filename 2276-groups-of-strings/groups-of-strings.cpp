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

    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int,int> mpToInd, mpToMsk;
        int n = words.size();
        DisjointSet du(n);
        
        for(int i = 0; i < n; i++){
            string x = words[i];
            int temp = 0;
            for(auto c: x){
                temp |= (1 << (c-'a'));
            }
            mpToMsk[i] = temp;

            if(mpToInd.count(temp)){
                du.unite(i, mpToInd[temp]);
            }
            else{
                mpToInd[temp] = i;
            }
        }
        
        for(int k = 0; k < n; k++){
                int msk = mpToMsk[k];
                // remove
                for(int i = 0; i < 26; i++){
                    if(((msk>>i) & 1) == 1){
                        int newMsk = msk & ~(1 << i);
                        if(mpToInd.count(newMsk)){
                            du.unite(k,mpToInd[newMsk]);    
                        }
                    }
                }
                // add
                for(int i = 0; i < 26; i++){
                    if(((msk>>i) & 1) == 0){
                        int newMsk = msk | (1 << i);
                        if(mpToInd.count(newMsk)){
                            du.unite(k,mpToInd[newMsk]);
                        }
                    }
                }

                // change
                for(int i = 0; i < 26; i++){
                    if(((msk>>i) & 1) == 1){
                        int tempMsk = msk & ~(1 << i);

                        for(int j = 0; j < 26; j++){
                            if(((msk>>j) & 1) == 0){
                                int newMsk = tempMsk | (1 << j);
                                if(mpToInd.count(newMsk)){
                                    du.unite(k,mpToInd[newMsk]); 
                                }
                            }
                        }
                    }
                }
        }

        set<int> groups;
        int maxSize = 1;
        for(int i = 0; i < n; i++){
            groups.insert(du.findPar(i));
            maxSize = max(maxSize, du.getSize(i));
        }
        int cnt = groups.size();
        return {cnt, maxSize};
    }
};