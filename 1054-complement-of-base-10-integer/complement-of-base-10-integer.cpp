class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)return 1;

        int ans = 0;
        int cnt = 0;
        while(n){
            if((n&1) == 0){
                ans += (1 << cnt);
            }
            n = n/2;
            cnt++;
        }
        return ans;
    }
};