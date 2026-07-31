class Solution {
public:

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        val = -1;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
    int findMaximumXOR(vector<int>& nums) {
        TreeNode* root = new TreeNode();

        for(int i = 0; i < nums.size(); i++){
            TreeNode* curr = root;
            for(int j = 31; j >= 0; j--){
                int dig = (nums[i]>>j)&1;
                if(dig == 0){
                    if(curr->left == NULL){
                        curr->left = new TreeNode(dig);
                    }
                    curr = curr->left;
                }
                else{
                    if(curr->right == NULL){
                        curr->right = new TreeNode(dig);
                    }
                    curr = curr->right;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i], y = 0;
            TreeNode* curr = root;
            for(int j = 31; j >= 0; j--){
                int dig = (x >> j) & 1;
                if(dig){
                    if(curr->left != NULL){
                        curr = curr->left;
                    }
                    else if (curr->right){
                        y |= (1<<j);
                        curr = curr->right;
                    }
                }
                else{
                    if(curr->right != NULL){
                        y |= (1<<j);
                        curr = curr->right;
                    }
                    else{
                        curr = curr->left;
                    }
                }
            }

            ans = max(ans,x^y);
        }
        return ans;
    }
};