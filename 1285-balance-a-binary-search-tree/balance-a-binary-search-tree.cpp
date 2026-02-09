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
    TreeNode* balanced(int l, int r , vector<int>& arr){
        if(l > r)return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = balanced(l,mid-1,arr);
        root->right = balanced(mid+1,r,arr);
        return root;
    }
    void dfs(TreeNode* root, vector<int>& arr){
        if(root == NULL)return;
        if(root->left)dfs(root->left,arr);
        arr.push_back(root->val);
        if(root->right)dfs(root->right,arr);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        if(root)dfs(root,arr);
        int s = 0, r = arr.size()-1;
        TreeNode* ans = balanced(s,r,arr);
        return ans;
        
    }
};