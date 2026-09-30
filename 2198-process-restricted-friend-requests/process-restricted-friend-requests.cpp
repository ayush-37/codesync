class Solution {
public:
    
    struct DisjointSet{
        int n;
        vector<int> par, size;
        unordered_map<int,unordered_set<int>> noFriends;
        unordered_map<int,unordered_set<int>> friends;

        DisjointSet(int x){
            n = x;
            par.assign(n,0);
            size.assign(n,1);
            for(int i = 0; i < n; i++)par[i] = i;
        }

        int findPar(int x){
            if(par[x] == x)return x;
            return par[x] = findPar(par[x]);
        }

        bool unite(int a, int b){
            int pa = findPar(a), pb = findPar(b);
            if(pa == pb)return true;

            bool can = true;

            for(auto x: friends[pb]){
                if(noFriends[pa].count(x)){
                    can = false;
                    break;
                }
            }
            for(auto x: friends[pa]){
                if(noFriends[pb].count(x)){
                    can = false;
                    break;
                }
            }
            
            if(!can)return can;

            if(size[pa] >= size[pb]){
                size[pa] += size[pb];
                par[pb] = pa;
                for(auto x: friends[pb]){
                    friends[pa].insert(x);
                }
                for(auto x: noFriends[pb]){
                    noFriends[pa].insert(x);
                }
            }
            else{
                size[pb] += size[pa];
                par[pa] = pb;
                for(auto x: friends[pa]){
                    friends[pb].insert(x);
                }
                for(auto x: noFriends[pa]){
                    noFriends[pb].insert(x);
                }
            }

            return can;
        }

        void addMember(bool isFriend, int u, int v){
            if(isFriend){
                friends[u].insert(v);
                friends[v].insert(u);
            }
            else{
                noFriends[u].insert(v);
                noFriends[v].insert(u);
            }
        }
    };

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DisjointSet du(n);

        for(auto x: restrictions){
            int u = x[0], v = x[1];
            du.addMember(false, u,v);
        }

        for(int i = 0; i < n; i++){
            du.addMember(true, i,i);
        }

        int m = requests.size();
        vector<bool> ans(m);
        for(int i = 0; i < m; i++){
            int u = requests[i][0], v = requests[i][1];
            ans[i] = du.unite(u,v);
        }

        return ans;
    }
};