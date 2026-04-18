class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n, rev = 0;
        while(temp){
            int r = temp%10;
            rev = rev*10 + r;
            temp/=10;
        }
        return abs(rev-n);
    }
};