class Solution {
public:
    int solve(vector<int>& memo, int msk, int n){
        if(msk == (1<<n)-1)return 1;
        if(memo[msk] != -1)return memo[msk];

        int pos = __builtin_popcount(msk)+1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(msk & 1<<i)continue; // already used
            int num = i+1;
            if((num%pos == 0) || (pos%num == 0)){
                ans += solve(memo,msk|(1<<i),n);
            }
        }
        return memo[msk] = ans;
    }
public:
    int countArrangement(int n) {
        vector<int> memo(1<<n,-1);
        return solve(memo,0,n);

    }
};