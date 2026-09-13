class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        for (int r = -(n - 1); r <= n - 1; r++) {
            for (int c = -(n - 1); c <= n - 1; c++) {

                int temp = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        int ni = i + r;
                        int nj = j + c;

                        // Check whether shifted position
                        // is inside img2
                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < n) {

                            if (img1[i][j] == 1 &&
                                img2[ni][nj] == 1) {
                                temp++;
                            }
                        }
                    }
                }

                ans = max(ans, temp);
            }
        }

        return ans;
    }
};