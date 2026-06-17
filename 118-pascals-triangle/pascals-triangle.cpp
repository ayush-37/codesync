class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int> temp(i+1,1);
            for(int j = 0;!ans.empty() && j+1 < ans.back().size(); j++)temp[j+1] = ans[i-1][j]+ans[i-1][j+1];
            ans.push_back(temp);
        }
        return ans;
    }
};