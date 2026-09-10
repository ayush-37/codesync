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
    int ans;
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        auto [s, n] = dfs(root);
        return ans;
    };

    pair<int,int> dfs(TreeNode* root){
        if(root == nullptr) return {0,0};

        pair<int,int> l = {0,0}, r = {0,0};

        if(root->left) l = dfs(root->left);
        if(root->right) r = dfs(root->right);

        int sum = root->val + l.first + r.first;
        int tot = 1 + l.second + r.second;

        if(root->val == (int)(sum/tot))ans++;

        // cout<<root->val<<" - "<<sum<<" , "<<tot<<endl;
        return {sum, tot};
    }


};