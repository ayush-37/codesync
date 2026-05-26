class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cap(26,0),small(26,0);
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'a' && word[i] <= 'z')small[word[i] - 'a']++;
            else cap[word[i]-'A']++;
        }

        int ans = 0;
        for(int i = 0; i < 26; i++)if(cap[i] > 0 && small[i] > 0)ans++;
        return ans;
    }
};