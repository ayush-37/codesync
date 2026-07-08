class Solution {
public:
    long long sumAndMultiply(int n) {
        int temp = n;
        int sum = 0, r = 0;
        string s = "";
        while(temp){
            r = temp%10;
            if(r!= 0){
                s.push_back(r+'0');
                sum += r;
            }
            temp/=10;
        }
        long long ans = 0;
        for(int i = s.size()-1; i >= 0; i--){
            int c = s[i] - '0';
            ans = ans*10 + c;
        }
        ans *= sum;
        return ans;
    }
};