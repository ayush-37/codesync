class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> v(n+1,false);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                int rem = i - j*j;
                if(!v[rem]){
                    v[i] = true;
                    break;
                }
            }
        }
        return v[n];
    }
};