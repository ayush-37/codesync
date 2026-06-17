class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevRow = nums;
        for(int i = 1; i <= n-1; i++){
            vector<int> currRow(n-i,0);
            for(int j = 0; j+1 < prevRow.size(); j++){
                currRow[j] = (prevRow[j]+prevRow[j+1])%10;
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }
};