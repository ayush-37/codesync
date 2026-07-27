class Solution {
public:
    bool solve(int msk, int cnt, int n, int& t,unordered_map<int,bool>& memo){
        if(memo.find(msk) != memo.end())return memo[msk];

        for(int i = 1; i <= n; i++){
            if(((msk >> i) & 1) == 0){
                if(cnt+i >= t || !solve((msk|(1<<i)), cnt+i, n, t,memo))return memo[msk] = true;
            }
        }

        memo[msk] = false;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int n = maxChoosableInteger, t = desiredTotal;
        if(n >= t)return true;
        if((n*(n+1))/2 < t)return false;

        unordered_map<int,bool> memo;
        return solve(0,0,n,t,memo);
    }
};