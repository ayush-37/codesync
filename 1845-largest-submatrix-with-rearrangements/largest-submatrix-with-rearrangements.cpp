class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<pair<int,int>> prevHeight;
        int ans = 0;
        for(int row = 0; row < n; row++){
            vector<pair<int,int>> currHeight;
            vector<int> seen(m,0);
            for(auto [h,col]: prevHeight){
                if(matrix[row][col] == 1){
                    currHeight.push_back({h+1,col});
                    seen[col] = 1;
                }
            }

            for(int col = 0; col < m; col++){
                if(seen[col] == 0 && matrix[row][col] == 1)currHeight.push_back({1,col});
            }

            for(int i = 0; i < currHeight.size(); i++){
                int height = currHeight[i].first;
                int width = i+1;
                ans = max(ans,height*width);
            }

            prevHeight = currHeight;
        }
        return ans;
    }
};