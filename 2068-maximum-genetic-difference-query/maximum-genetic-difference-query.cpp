class Solution {
public:

    struct TrieNode{
        TrieNode* child[2];
        int cnt;
        TrieNode(){
            child[0] = NULL, child[1] = NULL;
            cnt = 0;
        }
    };

    struct Trie{
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }

        void insert(int val, int d){
            TrieNode* node = root;

            for(int i = 31; i >= 0; i--){
                int bit = (val >> i) & 1;
                if(node->child[bit] == NULL)node->child[bit] = new TrieNode();
                node = node->child[bit];
                node->cnt += d;
            }
        }

        int maxXor(int val){
            int res = 0;
            TrieNode* node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (val >> i) & 1;
                if(node->child[bit ^ 1] != NULL && node->child[bit ^ 1]->cnt > 0){
                    res |= (1 << i);
                    node = node->child[bit ^ 1];
                }
                else node = node->child[bit];
            }
            return res;
        }
    };

    vector<vector<int>> graph;
    vector<vector<pair<int,int>>> query;
    vector<int> ans;

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        graph.resize(n);
        int source = -1;
        for(int i = 0; i < n; i++){
            if(parents[i] == -1)source = i;
            else graph[parents[i]].push_back(i);
        }

        int m = queries.size();
        query.resize(n);
        for(int i = 0; i < m; i++){
            int node = queries[i][0], val = queries[i][1];
            query[node].push_back({val, i});
        }
        ans.resize(m,0);

        Trie trie;
        dfs(source, trie);
        return ans;
        
    }

    void dfs(int u, Trie& trie){
        trie.insert(u,1);
        for(auto v: query[u]){
            auto [val, i] = v;
            ans[i] = trie.maxXor(val);
        }
        for(auto v: graph[u])dfs(v,trie);

        trie.insert(u,-1);
    }
};