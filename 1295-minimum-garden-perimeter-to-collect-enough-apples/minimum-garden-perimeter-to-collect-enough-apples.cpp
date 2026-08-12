class Solution {
public:
    using ll = long long;
    long long minimumPerimeter(long long neededApples) {
        ll maxLen = 1;
        ll cnt = 0;
        while(cnt < neededApples){
            cnt += (12*1LL)*maxLen*maxLen;
            if(cnt >= neededApples)break;
            maxLen++;
        }
        return maxLen*8;
    }
};