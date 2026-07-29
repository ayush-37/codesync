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
    using ll = long long;
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll,int> mp;
        ans = 0;
        mp[0] = 1;
        dfs(root,0,targetSum,mp);
        return ans;
    }

    void dfs(TreeNode* node,ll currSum, int& targetSum, unordered_map<ll,int>& mp){
        if(node == NULL)return;

        currSum += (ll)node->val;
        ll reqSum = currSum - 1LL * targetSum;
        if(mp.find(reqSum) != mp.end()){
            ans += mp[reqSum];
        }

        mp[currSum]++;

        if(node->left){
            dfs(node->left,currSum, targetSum, mp);
        }

        if(node->right){
            dfs(node->right,currSum, targetSum, mp);
        }

        mp[currSum]--;
        if(mp[currSum] == 0)mp.erase(currSum);

    }
};