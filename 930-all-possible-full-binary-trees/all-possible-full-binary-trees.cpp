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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0)return {};
        if(n == 1){
            TreeNode* root = new TreeNode();
            return {root};
        }

        vector<TreeNode*> ans;
        for(int i = 1; i < n; i+=2){
            vector<TreeNode*> leftFbt = allPossibleFBT(i);
            vector<TreeNode*> rightFbt = allPossibleFBT(n-i-1);

            for(auto x: leftFbt){
                for(auto y: rightFbt){
                    TreeNode* root = new TreeNode();
                    root->left = x;
                    root->right = y;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};