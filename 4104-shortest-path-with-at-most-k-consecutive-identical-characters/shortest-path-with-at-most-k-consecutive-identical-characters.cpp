class Solution {
public:
    using ll = long long;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto x: edges){
            int u = x[0], v = x[1], w = x[2];
            graph[u].push_back({v,w});
        }

        vector<vector<ll>> dist(n, vector<ll>(k+1,LLONG_MAX));
        
        dist[0][1] = 0;
        priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;
        pq.push({0,0,1});   // cost, node, cnt

        while(!pq.empty()){
            auto [cost, node, cnt] = pq.top();
            pq.pop();

            if(cost != dist[node][cnt])continue;

            if(node == n-1)return cost;

            for(auto [nbr,wt] : graph[node]){
                int newCnt = 1;
                if(labels[node] == labels[nbr])newCnt = cnt+1;
                if(newCnt > k)continue;

                if(cost + wt < dist[nbr][newCnt]){
                    dist[nbr][newCnt] = cost + wt;
                    pq.push({cost + wt, nbr, newCnt});
                }
            }
        }

        return -1;
    }
};