class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> v(26);
        for(int i = 0; i < n; i++)v[s[i] - 'a']++;
        string ans(n,'0');
        int l = 0, r = n-1;
        for(int i = 0; i < 26; i++){
            while(v[i] > 1){
                ans[l] = 'a' + i;
                ans[r] = 'a' + i;
                l++,r--;
                v[i]-=2;
            }
        }
        char c = '1';
        for(int i = 0; i < 26; i++)if(v[i] == 1)c = 'a'+i;

        if(c=='1')return ans;
        else {
            ans[n/2] = c;
            return ans;
        }
    }
};