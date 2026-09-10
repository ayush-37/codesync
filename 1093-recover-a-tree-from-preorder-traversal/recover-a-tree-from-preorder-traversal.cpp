/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string order;
    int n;
    TreeNode* recoverFromPreorder(string traversal) {
        order = traversal;
        int idx = 0;
        n = traversal.size();
        return dfs(idx, 0);
    }

    TreeNode* dfs(int& idx, int lev){
        if(idx >= n)return NULL;

        int st = idx, dep = 0;
        while(idx < n && order[idx] == '-'){
            dep++;
            idx++;
        }

        if(dep < lev){
            idx = st;
            return NULL;
        }

        int num = 0;
        while(idx < n && order[idx] != '-'){
            num = num * 10 + (order[idx] - '0');
            idx++;
        }

        TreeNode* node = new TreeNode(num);

        node->left = dfs(idx, lev+1);
        node->right = dfs(idx, lev+1);

        return node;

    }
};