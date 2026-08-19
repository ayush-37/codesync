class Solution {
public:
    int minSteps(int n) {
        if(n == 1)return 0;
        
        vector<int> ans(n+1,0);
        ans[1] = 0, ans[2] = 2;
        for(int i = 3; i <= n; i++){
            for(int j = i/2; j >= 1; j--){
                if(i % j == 0){
                    ans[i] = ans[j] + (i/j);
                    break;
                }
            }
        }
        return ans[n];
    }
};