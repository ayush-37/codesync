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
private:
    int dfs(TreeNode* root){
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL)return 1;
        else{
            int l1 = dfs(root->left);
            if(l1 == INT_MAX)return INT_MAX;
            int l2 = dfs(root->right);
            if(l2 == INT_MAX)return INT_MAX;
            if(abs(l2-l1) > 1)return INT_MAX;
            else return max(l2,l1)+1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        int l1 = dfs(root->left);
        if(l1 == INT_MAX)return false;
        int l2 = dfs(root->right);
        if(l2 == INT_MAX)return false;
        if(abs(l2-l1) > 1)return false;
        else return true;
    }
};