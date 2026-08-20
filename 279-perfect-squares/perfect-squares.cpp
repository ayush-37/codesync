class Solution {
public:
    int numSquares(int n) {
        vector<int> ans(n+1,0);
        vector<int> sq;
        for(int i = 1; i*i <= n; i++){
            ans[i*i] = 1;
            sq.push_back(i*i);
        }

        for(int i = 2; i <= n; i++){
            if(ans[i] != 0)continue;
            int temp = i;
            for(auto x: sq){
                if(x > i)break;
                int cnt = i/x + ans[i%x];
                temp = min(temp,cnt);
            }
            ans[i] = temp;
        }
        return ans[n];
    }
};