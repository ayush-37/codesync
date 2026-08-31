class Solution {

/*
    Approach: Binary Trie + Prefix Counting

    We need to count pairs (i, j) such that:
        low <= (nums[i] XOR nums[j]) <= high

    Instead of checking every pair in O(n^2), I process the array
    from left to right and maintain all previously seen numbers
    inside a Binary Trie.

    For every current number x:

        1. Count previous numbers y such that:
               x XOR y <= high

        2. Count previous numbers y such that:
               x XOR y <= low - 1

        3. Their difference gives:
               low <= x XOR y <= high

    Therefore:
        answer = count(XOR <= high) - count(XOR <= low - 1)


    Why Binary Trie?

    Each number is stored bit-by-bit in the Trie.
    While querying x XOR y <= k, I process bits from the most
    significant bit to the least significant bit.

    - If the current bit of k is 0:
          XOR bit must also be 0.
          Otherwise XOR would become greater than k.

    - If the current bit of k is 1:
          There are two possibilities:
          
          1. Make XOR bit 0:
                 0 < 1
             So the XOR becomes smaller than k.
             Every number in that Trie subtree is valid,
             so I add its cnt directly.

          2. Make XOR bit 1:
                 1 == 1
             The XOR is still equal to k so far,
             so I continue checking the remaining bits.


    Why cnt?

    Each TrieNode stores cnt = number of previously inserted
    values passing through that node.

    This allows me to count an entire Trie subtree in O(1)
    once the XOR prefix is already smaller than k, instead of
    traversing every number in that subtree.


    Why query before insert?

    For every x, the Trie contains only numbers that appeared
    before x. Therefore, every pair is counted exactly once.

        query(x)
        insert(x)

    If I inserted x before querying, x could be paired with
    itself.


    Time Complexity:

    Let B = number of bits (32).

    For each number:
        2 queries + 1 insertion = O(B)

    For n numbers:
        O(n * B)

    Since B = 32 is constant:
        O(n)

    Space Complexity:
        O(n * B) for the Binary Trie
        Since B is constant:
        O(n)
*/

public:
    struct TrieNode{
        TrieNode* child[2];
        int cnt;
        TrieNode(){
            child[0] = NULL , child[1] = NULL;
            cnt = 0;
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
                int d = (x>>i) & 1;
                if(node->child[d] == NULL)node->child[d] = new TrieNode();
                node = node->child[d];
                node->cnt++;
            }
        }

        int query(int x, int k){
            TrieNode* node = root;
            int ans = 0;
            for(int i = 31; i >= 0; i--){
                if(node == NULL)break;
                int kd = (k >> i)&1;
                int xd = (x >> i)&1;
                if(kd == 1){
                    if(node->child[xd] != NULL)ans += node->child[xd]->cnt;
                    node = node->child[1-xd];
                }
                else{
                    node = node->child[xd];
                }
            }

            if(node != nullptr)
                ans += node->cnt;

            return ans;
        }
    };
    int countPairs(vector<int>& nums, int low, int high) {
        int cntLow = 0, cntHigh = 0;
        Trie trie;
        for(auto x: nums){
            cntLow += trie.query(x,low-1);
            cntHigh += trie.query(x,high);
            trie.insert(x);
        }

        return cntHigh - cntLow;
    }
};