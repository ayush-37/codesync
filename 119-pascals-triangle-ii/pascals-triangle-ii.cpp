class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; i++){
            vector<int> temp(i+1,1);
            for(int j = 0;!ans.empty() && j+1 < ans.size(); j++)temp[j+1] = ans[j]+ans[j+1];
            ans = temp;
        }
        return ans;
    }
};