class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while((s.size() < k) && (n--)){
            string t = "1";
            int i = s.size()-1;
            while(i >= 0){
                if(s[i] == '0')t += '1';
                else t += '0';
                i--;
            }
            s += t;
        }
        char ans = '0';
        for(int i = 0; i < s.size(); i++){
            if(i+1 == k){
                ans = s[i];
                break;
            }
        }
        return ans;
    }
};