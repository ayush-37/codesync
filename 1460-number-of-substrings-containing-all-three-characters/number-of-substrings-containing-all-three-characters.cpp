class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        int l = 0, r = 0;
        while(r < s.size()){
            mp[s[r]]++;
            while(l < r && mp['a'] && mp['b'] && mp['c']){
                ans += ((int)s.size() - r);
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};