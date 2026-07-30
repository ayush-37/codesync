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
    unordered_map<int ,vector<TreeNode*>> mp;
    vector<TreeNode*> generateTrees(int n) {
        if(n == 1){
            TreeNode* root = new TreeNode(1);
            return {root};
        }

        return generate(1,n);
    }
    
    vector<TreeNode*> generate(int start, int end){
        if(start > end){
            return {NULL};
        }

        if(mp.find(start*100 + end) != mp.end()){
            return(mp[start*100 + end]);
        }

        vector<TreeNode*> ans;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = generate(start,i-1);
            vector<TreeNode*> right = generate(i+1,end);

            for(auto x: left){
                for(auto y: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;

                    ans.push_back(root);
                }
            }
        }

        return mp[start*100 + end] = ans;

    }
    
};