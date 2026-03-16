class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> st;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> sumLeft(n+2,vector<int>(m+2,0)), sumRight(n+2,vector<int>(m+2,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sumRight[i][j] = sumRight[i-1][j-1] + grid[i-1][j-1];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                sumLeft[i][j] = sumLeft[i-1][j+1] + grid[i-1][j-1];
            }
        }


        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                st.insert(grid[i-1][j-1]);
                int x = 1;
                while(j-x > 0 && j+x < m+1 && i + 2*x < n+1){
                    int x1 = i, y1 = j;
                    int x2 = i+x, y2 = j-x;
                    int x3 = i+x, y3 = j+x;
                    int x4 = i+2*x, y4 = j;

                    int ans = 0;
                    int sum1 = sumLeft[x2][y2] - sumLeft[x1-1][y1+1];
                    int sum2 = sumRight[x3][y3] - sumRight[x1-1][y1-1];
                    int sum3 = sumRight[x4][y4] - sumRight[x2-1][y2-1];
                    int sum4 = sumLeft[x4][y4] - sumLeft[x3-1][y3+1];
                    ans +=  (sum1+sum2+sum3+sum4) - (grid[x1-1][y1-1]+grid[x2-1][y2-1]+grid[x3-1][y3-1]+grid[x4-1][y4-1]);

                    st.insert(ans);
                    x++;
                }
            }
        }

        vector<int> temp(st.begin(),st.end());
        sort(temp.rbegin(),temp.rend());
        vector<int> final;
        for(int i = 0; i < temp.size(); i++){
            final.push_back(temp[i]);
            if(final.size() == 3)break;
        }
        return final;
        
    }
};