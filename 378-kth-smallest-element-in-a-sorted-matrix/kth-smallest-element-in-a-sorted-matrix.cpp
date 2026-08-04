class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> ans;
        for(auto& x: matrix){
            for(auto& y: x)ans.push_back(y);
        }
        sort(ans.begin(),ans.end());
        return (ans[k-1]);
    }
};