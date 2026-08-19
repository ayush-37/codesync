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
        deque<TreeNode*> dq;
        for(auto x: nums){
            TreeNode* curr = new TreeNode(x);
            while(!dq.empty() && dq.back()->val < x){
                auto f = dq.back();
                dq.pop_back();
                curr->left = f;
            }
            if(!dq.empty())dq.back()->right = curr;
            dq.push_back(curr);
        }
        return dq.front();
    }
};