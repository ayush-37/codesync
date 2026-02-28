class Solution {
private:
    int cnt(int n){
        int c = 0;
        while(n){
            c++;
            n/=2;
        }
        return c;
    }
public:
    int concatenatedBinary(int n) {
        long long ans = 1;
        int mod = 1e9 + 7;
        if(n == 1)return ans;
        vector<int> msk(32,0);
        for(int i = 2; i <= n; i++){
            long long temp = ans;
            int d = cnt(i);
            long long newAns = 0;
            for(int j = 0; j < 32; j++){
                if(temp == 0)break;
                if(temp&1LL){
                    msk[j] = 1;
                }
                temp = temp/2;
            }
            for(int j = 0; j < 32; j++){
                if(msk[j])newAns = (newAns + (1LL<<(j+d)%mod))%mod;
            }
            ans = (newAns+(long long)i)%mod;
            msk.assign(32,0);
        }
        return (int)ans;
    }
};

