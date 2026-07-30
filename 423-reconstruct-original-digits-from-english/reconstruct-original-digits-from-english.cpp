class Solution {
public:
    string originalDigits(string s) {
        vector<int> v(10,0),freq(26,0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }

        //special letters
        v[0] = freq['z'-'a'];
        v[2] = freq['w'-'a'];
        v[4] = freq['u'-'a'];
        v[6] = freq['x'-'a'];
        v[8] = freq['g'-'a'];

        //common letters
        v[1] = freq['o'-'a'] - (v[0] + v[2] + v[4]);
        v[3] = freq['h'-'a'] - (v[8]);
        v[5] = freq['f'-'a'] - (v[4]);
        v[7] = freq['s'-'a'] - (v[6]);
        v[9] = freq['i'-'a'] - (v[5] + v[6] + v[8]);
        
        string ans = "";

        for(int d = 0; d <= 9; d++){
            ans += string(v[d], char('0' + d));
        }

        return ans;
    }
};