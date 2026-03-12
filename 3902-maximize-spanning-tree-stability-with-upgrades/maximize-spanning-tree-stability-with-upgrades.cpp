class Solution {
class DisJointSet{
    vector<int> par,size;

    public:
    DisJointSet(int n){
        par.resize(n,0);
        size.resize(n,1);
        for(int i = 0; i < n; i++)par[i] = i;
    }

    int findPar(int n){
        if(par[n] == n)return n;
        else return par[n] = findPar(par[n]);
    }

    void unionBySize(int x, int y){
        int px = findPar(x);
        int py = findPar(y);

        if(px == py)return;

        if(size[px] < size[py]){
            size[py] += size[px];
            par[px] = py;
        }
        else{
            size[px] += size[py];
            par[py] = px;
        }
    }
};
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DisJointSet du(n);

        vector<vector<int>> must, mustNot;
        int ans = INT_MAX;
        for(auto x: edges){
            if(x.back()){
                must.push_back({x[0],x[1],x[2]});
                ans = min(ans,x[2]);
            }
            else{
                mustNot.push_back({x[0],x[1],x[2]});
            }
        }

        if(must.size() >= n)return -1;

        for(auto& vec: must){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            int pu = du.findPar(u);
            int pv = du.findPar(v);

            if(pu == pv)return -1;
            else du.unionBySize(u,v);
        }

        sort(mustNot.begin(), mustNot.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] > b[2];
        });

        int ed = must.size();
        vector<int> wts;
        for(auto& vec: mustNot){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            int pu = du.findPar(u);
            int pv = du.findPar(v);
            if(pu!=pv){
                du.unionBySize(u,v);
                ed++;
                wts.push_back(w);
            }
            if(ed == n-1)break;
        }

        for(int i = wts.size()-1; i >= 0 && k; i--,k--){
            wts[i]*=2;
        }
        if(!wts.empty()){
            sort(wts.begin(),wts.end());
            ans = min(ans,wts[0]);
        }
        
        return (ed == n-1)?ans:-1;


    }
};