class Solution {
public:
    vector<int> ans, vis;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        vis.resize(n);

        vector<vector<int>> tree(n);
        for(auto e: edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        vector<int> temp = solve(0,tree,labels);
        return ans;
    }

    vector<int> solve(int root, vector<vector<int>>& tree, string& labels){
        vector<int> ch(26,0);
        vis[root] = 1;
        for(auto child: tree[root]){
            if(vis[child])continue;
            vector<int> temp = solve(child, tree, labels);
            for(int i = 0; i < 26; i++)ch[i] += temp[i];
        }

        ch[labels[root]-'a']++;
        ans[root] = ch[labels[root] - 'a'];
        return ch;
    }
};