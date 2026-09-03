class Solution {
public:
    vector<vector<int>> graph;
    vector<int> vis, child, dis;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);    // create graph 
        vis.resize(n,0);    // create visited array
        child.resize(n,0);  // child[i] = no of childs of node i
        dis.resize(n,0);    // dis[i] = sum of the distances between the ith node in the tree and all other nodes in its subtree

        for(auto x: edges){
            int u = x[0], v = x[1];
            graph[v].push_back(u);
            graph[u].push_back(v);
        }

        vis[0] = 1;
        pair<int,int> res = dfs(0);  // dfs to get no of child of node 0 and total distance from node 0 to all other nodes 

        vector<int> ans(n); // ans array
        ans[0] = res.second; // our base case

        vis.assign(n,0);  // reassign visited array with 0 for bfs
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr: graph[node]){
                if(vis[nbr] == 0){
                    vis[nbr] = 1;
                    q.push(nbr);
                    int c = child[nbr] + 1;
                    ans[nbr] = ans[node] - c + n - c; 
                    // on shifting root from node to nbr all the nbr's child and nbr contribute -1 to answer (the distance decreases by 1 for every node in that subtree) and all the left over nodes contributes +1 to answer 
                }
            }
        }
        return ans;
    }

    pair<int,int> dfs(int s){
        int c = 0, d = 0;
        for(auto n: graph[s]){
            if(vis[n] == 0){
                vis[n] = 1;
                auto [cn, dn] = dfs(n);
                c += cn + 1;
                d += 1 + cn + dn;
            }
        }

        child[s] = c, dis[s ] = d;
        return {c,d};
    }
    
};