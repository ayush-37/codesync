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
    vector<int> ans;
    void recoverTree(TreeNode* root) {
        solve(root);
        sort(ans.begin(),ans.end());

        int i = 0;
        put(root, i);
        return;
    }

    void put(TreeNode* root, int& i){
        if(root == NULL)return ;
        if(root->left)put(root->left,i);
        root->val = ans[i];
        i++;
        if(root->right)put(root->right,i);    
    }

    void solve(TreeNode* root){
        if(root == NULL)return;

        ans.push_back(root->val);
        if(root->left)solve(root->left);
        if(root->right)solve(root->right);
    }
};