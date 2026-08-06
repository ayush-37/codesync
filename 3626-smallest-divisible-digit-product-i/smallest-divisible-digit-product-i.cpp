class Solution {
public:
    int smallestNumber(int n, int t) {
        int last = ((n+9)/10)*10;
        for(int i = n; i < last; i++){
            int prod = 1, temp = i;
            while(temp){
                int r = temp%10;
                prod *= r;
                temp/=10;
            }
            if(prod % t == 0)return i;
        }
        return last;
    }
};