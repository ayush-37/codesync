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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL)return NULL;
        pair<int,TreeNode*> p = dfs(root);
        return p.second;
    }

    pair<int,TreeNode*> dfs(TreeNode* node){
        if(node == NULL)return {0,NULL};

        
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if(left.first > right.first){
            return {left.first+1, left.second};
        }else if(left.first < right.first){
            return {right.first+1, right.second};
        }
        else{
            return {left.first+1,node};
        }
    }
};