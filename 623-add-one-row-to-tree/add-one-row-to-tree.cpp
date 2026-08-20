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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        int d = 1;
        queue<TreeNode*> q;
        q.push(root);
        while((d+1 != depth) && !q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            d++;
        }

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            TreeNode* tempLeft = node->left;
            TreeNode* tempRight = node->right;
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = tempLeft;
            node->right->right = tempRight;
           
        }

        return root;
    }
};