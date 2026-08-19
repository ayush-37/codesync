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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = create(0,n-1,nums);
        return root;
    }

    TreeNode* create(int s, int e, vector<int>& nums){
        if(s == e){
            TreeNode* root = new TreeNode(nums[s]);
            return root;
        }

        if(s > e)return NULL;

        int ind = s, maxi = nums[s];
        for(int i = s; i <= e; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                ind = i;
            }
        }

        TreeNode* root = new TreeNode(nums[ind]);
        root->left = create(s,ind-1,nums);
        root->right = create(ind+1,e,nums);

        return root;
    }
};