class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cap(26,INT_MAX),small(26,-1);
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                small[word[i]-'a'] = max(i,small[word[i]-'a']);
            }
            else{
                cap[word[i]-'A'] = min(i,cap[word[i]-'A']);
            }
        }
        int ans = 0;
        for(int i = 0; i < 26; i++)if((cap[i] != INT_MAX) && (small[i] != -1) && (small[i] < cap[i]))ans++;
        return ans;
    }
};