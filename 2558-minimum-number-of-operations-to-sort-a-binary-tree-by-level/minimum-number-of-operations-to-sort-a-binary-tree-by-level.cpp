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

    int minimumOperations(TreeNode* root) {
        ans = 0;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    temp.push_back(node->left->val);
                    q.push(node->left);
                }
                if(node->right){
                    temp.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            
            solve(temp);
        }
        return ans;
    }

    void solve(vector<int> curr){
        if(curr.size() <= 1)return;

        unordered_map<int,int> mp;
        for(int i = 0; i < curr.size(); i++){
            mp[curr[i]] = i;
        }

        vector<int> temp(curr.begin(), curr.end());
        sort(temp.begin(), temp.end());

        for(int i = 0; i < curr.size(); i++){
            if(curr[i] != temp[i]){
                ans++;
                int current = curr[i], ideal = temp[i];
                int idx = mp[temp[i]];

                swap(curr[i], curr[idx]);
                mp[current] = idx;

            }
        }
    }
};