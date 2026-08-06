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
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if(root == NULL)return 0;
        if(memo.find(root) != memo.end())return memo[root];

        // case 1 consider root;
        int l = 0, r = 0;
        if(root->right)r = rob(root->right->left) + rob(root->right->right);
        if(root->left)l = rob(root->left->left) + rob(root->left->right);

        int c1 = root->val + l + r;

        // leave root;
        l = 0, r = 0;
        l = rob(root->left);
        r = rob(root->right);

        int c2 = l + r;

        return memo[root] = max(c1,c2);
    }
};