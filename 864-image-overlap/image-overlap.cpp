class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int temp = 0;
                for(int i = 0; i+r < n; i++){
                    for(int j = 0; j+c < n; j++){
                        if((img1[i][j] == 1) && (img1[i][j] == img2[i+r][j+c]))temp++;
                    }
                }
                ans = max(ans, temp);
            }
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int temp = 0;
                for(int i = 0; i+r < n; i++){
                    for(int j = n-1; j-c >= 0; j--){
                        if((img1[i][j] == 1) && (img1[i][j] == img2[i+r][j-c]))temp++;
                    }
                }
                ans = max(ans, temp);
            }
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int temp = 0;
                for(int i = n-1; i-r >= 0; i--){
                    for(int j = 0; j+c < n; j++){
                        if((img1[i][j] == 1) && (img1[i][j] == img2[i-r][j+c]))temp++;
                    }
                }
                ans = max(ans, temp);
            }
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                int temp = 0;
                for(int i = n-1; i-r >= 0; i--){
                    for(int j = n-1; j-c >= 0; j--){
                        if((img1[i][j] == 1) && (img1[i][j] == img2[i-r][j-c]))temp++;
                    }
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};