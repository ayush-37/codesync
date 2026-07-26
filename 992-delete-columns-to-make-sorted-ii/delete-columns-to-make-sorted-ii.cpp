class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(),ans = 0;
        vector<int> rowSorted(n+1,0);
        for(int col = 0; col < m; col++){
            bool deleted = false;
            for(int row = 0; row < n-1; row++){
                if(strs[row][col] > strs[row+1][col]){
                    if(!rowSorted[row]){
                        deleted = true;
                        ans++;
                        break;
                    }
                }
            }
            if(deleted)continue;
            for(int i = 0; i < n-1; i++)rowSorted[i] |= (strs[i][col] < strs[i+1][col]);
        }
        return ans;
    }
};