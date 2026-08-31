class Solution {
public:

    struct TrieNode{
        TrieNode* child[2];
        TrieNode(){
            child[0] = NULL, child[1] = 0;
        }
    };

    struct Trie{
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }

        void insert(int x){
            TrieNode* node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (x >> i) & 1;
                if(node->child[bit] == NULL)node->child[bit] = new TrieNode();
                node = node->child[bit];
            }
        }

        int maxXor(int x){
            TrieNode* node = root;
            int res = 0;
            for(int i = 31; i >= 0; i--){
                int bit = (x >> i) & 1;
                if(node->child[1-bit] != NULL){
                    res |= (1 << i);
                    node = node->child[1-bit];
                }
                else node = node->child[bit];
            }

            return res;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        Trie trie;
        for(auto x: nums){
            trie.insert(x);
            ans = max(ans, trie.maxXor(x));
        }

        return ans;
    }
};