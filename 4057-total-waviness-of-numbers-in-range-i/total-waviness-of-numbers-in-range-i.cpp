class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2 < 100)return 0;
        int cnt = 0;
        for(int i = num1; i <= num2; i++){
            string s = to_string(i);
            int j = 1;
            while(j < s.size()-1){
                if(s[j-1] < s[j] && s[j+1] < s[j])cnt++;
                if(s[j-1] > s[j] && s[j+1] > s[j])cnt++;
                j++;
            }
        }
        return cnt;
    }
};