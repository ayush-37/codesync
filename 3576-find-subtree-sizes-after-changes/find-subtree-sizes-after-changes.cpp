
class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> newGraph;
    vector<int> tree;

    void buildTree(int node, vector<int> last,
                   string& s, vector<int>& newPar) {

        int c = s[node] - 'a';

        if(last[c] != -1)
            newPar[node] = last[c];

        last[c] = node;

        for(auto nbr : graph[node]) {
            buildTree(nbr, last, s, newPar);
        }
    }

    int dfs(int node) {
        int cnt = 1;

        for(auto nbr : newGraph[node]) {
            cnt += dfs(nbr);
        }

        return tree[node] = cnt;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        graph.assign(n, {});
        newGraph.assign(n, {});
        tree.assign(n, 0);

        vector<int> newPar = parent;

        for(int i = 1; i < n; i++) {
            graph[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        buildTree(0, last, s, newPar);

        for(int i = 1; i < n; i++) {
            newGraph[newPar[i]].push_back(i);
        }

        dfs(0);

        return tree;
    }
};
