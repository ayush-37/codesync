class Solution {
private:
void asc(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> dist(3,vector<int> (n,0));
        vector<vector<int>> tree(n);
        for(int i = 0; i < n-1; i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        unordered_map<int,int> mp;
        mp[x] = 0, mp[y] = 1, mp[z] = 2;
        vector<int> dest = {x,y,z};
        for(int i = 0; i < 3; i++){
            queue<int> q;
            q.push(dest[i]);
            vector<int> vis(n);
            vis[dest[i]] = 1;
            int lev = 0;
            while(!q.empty()){
                int s = q.size();
                for(int j = 0; j < s; j++){
                    int node = q.front();
                    dist[mp[dest[i]]][node] = lev;
                    q.pop();
                    for(auto nbr: tree[node]){
                        if(vis[nbr] == 0){
                            q.push(nbr);
                            vis[nbr] = 1;
                        }
                    }
                }
                lev++;
            }
        }

        long long cnt = 0, a = 0, b = 0, c = 1;
        for(int i = 0; i < n; i++){
            asc(dist[0][i],dist[1][i],dist[2][i]);
            a = dist[0][i], b = dist[1][i], c = dist[2][i];
            if(a*a + b*b == c*c)cnt++;
        }
        return (int)cnt;
    }
};