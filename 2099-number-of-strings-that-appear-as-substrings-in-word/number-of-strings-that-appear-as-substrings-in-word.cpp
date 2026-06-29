class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(int i = 0; i < patterns.size(); i++){
            string temp = patterns[i];
            int l = 0, r = 0;
            while(r < word.size() && l < temp.size()){
                if(temp[l] == word[r])l++;
                else{
                    r = r-l+1;
                    l = 0;
                    continue;
                }
                r++;
            }
            if(l == temp.size())cnt++;
        }
        return cnt;
    }
};