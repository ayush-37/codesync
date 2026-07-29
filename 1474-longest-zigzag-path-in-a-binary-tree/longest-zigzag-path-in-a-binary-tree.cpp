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
    int longestZigZag(TreeNode* root) {
        ans = 0;
        
        solve(root,0,true);
        solve(root,0,false);
        return ans;
    }
    void solve(TreeNode* node, int sum, bool left){
        if(node == NULL)return;

        ans = max(ans,sum);

        if(left){
            solve(node->left,sum+1,false);
            solve(node->right,1,true);
        }
        else{
            solve(node->right,sum+1,true);
            solve(node->left,1,false);
        }
    }
};