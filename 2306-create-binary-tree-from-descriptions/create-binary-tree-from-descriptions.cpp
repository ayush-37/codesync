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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<int>> mp;
        unordered_set<int> st;
        for(int i = 0; i < descriptions.size(); i++){
            int par = descriptions[i][0], child = descriptions[i][1], left = descriptions[i][2];
            st.insert(child);
            if(mp.count(par)){
                if(left){
                    mp[par][0] = child;
                }
                else{
                    mp[par][1] = child;
                }
            }
            else{
                vector<int> temp;
                if(left){
                    temp.push_back(child);
                    temp.push_back(-1);
                }
                else{
                    temp.push_back(-1);
                    temp.push_back(child);
                }
                mp[par] = temp;
            }
        }

        unordered_map<int,TreeNode*> keyToNode;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            int par = itr->first;
            auto v = itr->second;
            TreeNode* p;
            if(keyToNode.count(par))
                p = keyToNode[par];
            else {
                p = new TreeNode(par);
                keyToNode[par] = p;
            }
            if(v[0] != -1){
                if(keyToNode.count(v[0])){
                    p->left = keyToNode[v[0]];
                }
                else{
                    p->left = new TreeNode(v[0]);
                    keyToNode[v[0]] = p->left;
                }
            }
            if(v[1] != -1){
                if(keyToNode.count(v[1])){
                    p->right = keyToNode[v[1]];
                }
                else{
                    p->right = new TreeNode(v[1]);
                    keyToNode[v[1]] = p->right;
                }
            }
        }

        int ultPar = -1;
        for(int i = 0; i < descriptions.size(); i++){
            if(!st.count(descriptions[i][0])){
                ultPar = descriptions[i][0];
                break;
            }
        }
        return keyToNode[ultPar];
    }
};