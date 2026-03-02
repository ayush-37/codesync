class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> check(n,0);

        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 0)check[i]++;
                else break;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && check[j] < n-i-1)j++;
            if(j == n)return -1;
            ans += (j-i);
            while(j > i){
                swap(check[j],check[j-1]);
                j--;
            }
        }
        return ans;
    }
};