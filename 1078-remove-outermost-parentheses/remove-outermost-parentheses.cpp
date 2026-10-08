class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int l = 0, r = 0;
        int cnt = 0;
        while(r < s.size()){
            if(s[r] == '(')cnt++;
            else cnt--;

            if(cnt == 0){
                string temp = "";
                int len = (r-1) - (l+1) + 1;
                if(l+1 < r-1)temp = s.substr(l+1,len);
                ans += temp;

                l = r+1;
            }
            r++;
        }

        return ans;
    }
};