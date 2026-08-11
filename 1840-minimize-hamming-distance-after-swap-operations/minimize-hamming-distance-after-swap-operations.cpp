class Solution {
public:
    struct DisjointSet{
        vector<int> par,size;
        int n;
        DisjointSet(int x){
            n = x;
            par.resize(n+1,1);
            size.resize(n+1,1);

            for(int i = 0; i <= n; i++){
                par[i] = i;
            }
        }

        int findUpar(int x){
            if(par[x] == x)return x;
            else return par[x] = findUpar(par[x]);
        }

        void unionBySize(int a, int b){
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
    };

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> graph(n+1);
        vector<int> swapped(n,0);
        DisjointSet du(n);
        for(auto x: allowedSwaps){
            int a = x[0];
            int b = x[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
            swapped[a] = 1;
            swapped[b] = 1;
            du.unionBySize(a,b);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(swapped[i] == 0 && source[i] != target[i])cnt++;
        }

        for(int i = 0; i < n; i++){
            if(swapped[i] == 1){
                unordered_map<int,int> mp;
                vector<int> ind;
                int s = du.findUpar(i);
                queue<int> q;
                q.push(s);
                swapped[s] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    ind.push_back(node);
                    mp[source[node]]++;

                    for(auto nbr: graph[node]){
                        if(swapped[nbr] == 1){
                            q.push(nbr);
                            swapped[nbr] = 0;
                        }
                    }
                }

                int mismatch = 0;
                for(auto i : ind) {
                    if(mp.find(target[i]) != mp.end()) {
                        mp[target[i]]--;

                        if(mp[target[i]] == 0)
                            mp.erase(target[i]);

                        // One source element matched one target element
                    } else {
                        mismatch++;
                    }
                }
                                
                cnt+=mismatch;
            }
        }

        return cnt;
    }
};