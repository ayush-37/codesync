class Solution {
class DisJointSet{
    vector<int> size,par;
    public:
        DisJointSet(int n){
            size.resize(n+1,1);
            par.resize(n+1,0);
            for(int i = 0; i < n; i++)par[i] = i;
        }

        void unionBySize(int x, int y){
            int px = findPar(x);
            int py = findPar(y);

            if(px == py)return;
            if(size[px] >= size[py]){
                par[py] = px;
                size[px]+=size[py];
            }
            else{
                par[px] = py;
                size[py]+=size[px];
            }
        }

        int findPar(int x){
            if(par[x] == x)return x;
            else return par[x] = findPar(par[x]);
        }
};
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJointSet dsu(n);

        vector<int> par(n,0);
        for(int i = 0; i < n; i++)par[i] = i;

        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.count(accounts[i][j]) == 0){
                    mp[accounts[i][j]] = i;
                }
                else{
                    dsu.unionBySize(i,mp[accounts[i][j]]);
                }
            }
        }
        vector<set<string>> v(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                int ind = dsu.findPar(i);
                v[ind].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(v[i].empty())continue;
            vector<string> temp = {accounts[i][0]};
            for(auto x: v[i])temp.push_back(x);
            ans.push_back(temp);
        }
        return ans;
    }
};