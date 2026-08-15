class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            int a = (left >> i) & 1;
            int b = (right >> i) & 1;
            if(a != b)break;
            if(a == 1)ans = ans | (1<<i);
        }
        return ans;
    }
};