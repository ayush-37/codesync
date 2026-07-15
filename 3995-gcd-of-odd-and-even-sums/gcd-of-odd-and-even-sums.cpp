class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       int o = (n*(2 + (n-1)*2))/2, e = (n*(4 + (n-1)*2))/2;
       return gcd(o,e);
    }
};