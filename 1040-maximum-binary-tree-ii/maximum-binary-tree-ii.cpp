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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }

        if(val >= root->val){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        else{
            TreeNode* temp = root;
            while(temp->right != NULL && temp->right->val > val)temp = temp->right;
            TreeNode* t = temp->right;
            temp->right = new TreeNode(val);
            temp->right->left = t;
            return root;
        }
    }
};