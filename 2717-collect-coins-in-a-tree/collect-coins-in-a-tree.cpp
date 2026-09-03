class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);

        // Build graph
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            deg[u]++;
            deg[v]++;
        }

        queue<int> q;

        // --------------------------------------------------
        // Phase 1:
        // Remove all leaf nodes that don't contain a coin.
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && coins[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node]) {
                if (deg[nbr] == 0)
                    continue;

                deg[node]--;
                deg[nbr]--;

                if (deg[nbr] == 1 && coins[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // --------------------------------------------------
        // Phase 2:
        // Remove exactly TWO layers of leaf nodes.
        // These leaves contain coins, but we can collect
        // their coins from distance <= 2.
        // --------------------------------------------------

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                q.push(i);
            }
        }

        for (int round = 0; round < 2; round++) {

            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                for (int nbr : adj[node]) {
                    if (deg[nbr] == 0)
                        continue;

                    deg[node]--;
                    deg[nbr]--;

                    if (deg[nbr] == 1) {
                        q.push(nbr);
                    }
                }
            }
        }

        // Every remaining edge has to be traversed twice.
        // Sum of degrees = 2 * number of remaining edges.
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += deg[i];
        }

        return ans;
    }
};