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
    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }

    vector<int> solve(TreeNode* root){
        if(root == NULL)return {1,0,INT_MAX, INT_MIN};

        vector<int> left = solve(root->left);
        int isLeft = left[0], sumLeft = left[1], lmn = left[2], lmx = left[3];

        vector<int> right = solve(root->right);
        int isRight = right[0], sumRight = right[1], rmn = right[2], rmx = right[3];

        if(isLeft && isRight){
            if(root->val > lmx && root->val < rmn){
                int sum = root->val + sumLeft + sumRight;
                int mn = min(lmn, root->val);
                int mx = max(rmx, root->val);

                ans = max(ans, sum);
                return {1,sum, mn, mx};
            }
        }
        return {0,0,INT_MAX, INT_MIN};
    }
};