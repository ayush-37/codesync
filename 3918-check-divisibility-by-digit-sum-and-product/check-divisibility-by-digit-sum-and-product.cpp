class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, pro = 1, t = n;
        while(t){
            sum += (t%10);
            pro *= (t%10);
            t /= 10;
        } 

        return n%(sum+pro) == 0;
    }
};