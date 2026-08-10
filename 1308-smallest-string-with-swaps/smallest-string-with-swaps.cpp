class Solution {
public:
    struct DisjointSet{
        vector<int> par, size;
        int n;
        DisjointSet(int x){
            n = x;
            par.resize(n,1);
            size.resize(n,1);
            for(int i = 0; i < n; i++)par[i] = i;
        }

        int findUpar(int x){
            if(par[x] == x)return x;
            else return par[x] = findUpar(par[x]);
        }

        void unionBySize(int a, int b){
            int pa = findUpar(a);
            int pb = findUpar(b);
            if(pa == pb)return ;

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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DisjointSet d(n);

        vector<vector<int>> graph(n);

        vector<int> traverse(n,0);
        for(auto p: pairs){
            int a = p[0], b = p[1];
            traverse[a] = 1;
            traverse[b] = 1;
            graph[a].push_back(b);
            graph[b].push_back(a);
            d.unionBySize(a,b);
        }

        for(int i = 0; i < n; i++){
            if(traverse[i]){
                int source = d.findUpar(i);
                vector<char> c;
                vector<int> ind;
                queue<int> q;
                q.push(source);
                traverse[source] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    c.push_back(s[node]);
                    ind.push_back(node);

                    for(auto nbr: graph[node]){
                        if(traverse[nbr]){
                            q.push(nbr);
                            traverse[nbr] = 0;
                        }
                    }
                }

                sort(c.begin(),c.end());
                sort(ind.begin(),ind.end());

                for(int j = 0 ; j < c.size(); j++){
                    s[ind[j]] = c[j];
                }
            }
        }
        return s;
    }
};