class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long cnt = 1, temp = 1000;
        if(n < 1000)return ans;
        while(temp*1000 <= n){
            long long t = (temp*1000 - temp)* cnt;
            // cout<<(temp*1000 - temp)<<" "<<cnt<<endl;
            ans += t;
            temp *= 1000;
            cnt++;
        }
        ans += (n-temp + 1) * cnt;
        return ans;
    }
};