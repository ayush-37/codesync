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
    int moves;
    int distributeCoins(TreeNode* root) {
        moves = 0;
        solve(root);
        return moves;
    }

    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = solve(root->left);       // extra coins received from left child
        int right = solve(root->right);     // extra coins received from right child
        moves += abs(left) + abs(right);    // total moves taken to get extra coins from children
        int extra = left + right + root->val - 1;   // extra coins which will be returned to parent
        return extra;
    }
};