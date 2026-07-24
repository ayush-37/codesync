class Solution {
public:
    int numSteps(string s) {
        int cnt = 0, carry = 0, n = s.size();
        for(int i = n-1; i >= 0; i--){
            if(carry == 0){
                if(i == 0)continue;
                else{
                    if(s[i] == '0')cnt++;
                    else{
                        carry = 1, cnt+=2;
                    }
                }
            }
            else{
                if(s[i] == '0')cnt+=2;
                else cnt++;
            }
        }
        return cnt;
    }
};