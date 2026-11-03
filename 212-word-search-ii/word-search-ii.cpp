class Solution {
public:
    unordered_set<string> ans;
    int n, m;
    vector<int> dir ={-1,0,1,0,-1};
    vector<vector<int>> vis;

    struct Node{
        bool wordEnd;
        vector<Node*> ch;

        Node(){
            wordEnd = false;
            ch.assign(26,NULL);
        }
    };
    struct TrieNode{
        Node* root;

        TrieNode(){
            root = new Node();
        }

        void insert(string s){
            Node* node = root;
            for(char c: s){
                int i = c - 'a';
                if(node->ch[i] == NULL)node->ch[i] = new Node();
                node = node->ch[i];
            }

            node->wordEnd = true;
        }

        Node* getNode(){
            return root;
        }
    };
    void dfs(Node* node, int x, int y, string& curr, vector<vector<char>>& grid){
        if(node->wordEnd){
            ans.insert(curr);
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dir[i], ny = y + dir[i+1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0){
                char c = grid[nx][ny];
                if(node->ch[c-'a'] != NULL){
                    vis[nx][ny] = 1;
                    curr.push_back(c);
                    dfs(node->ch[c - 'a'], nx, ny, curr, grid);
                    curr.pop_back();
                    vis[nx][ny] = 0;
                }    
            }
        }
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
        TrieNode* trie = new TrieNode();
        for(auto s: words){
            trie->insert(s);
        }

        Node* root = trie->getNode();
        vis.assign(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c = board[i][j];
                if(root->ch[c -'a'] == NULL) continue;
                vis[i][j] = 1;
                string curr = "";
                curr.push_back(c);
                dfs(root->ch[c -'a'], i, j, curr, board);
                vis[i][j] = 0;
            }
        }

        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};