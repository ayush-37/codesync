class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int,int>>> wait(26);
        for(int i = 0; i < words.size(); i++){
            char first = words[i][0];
            wait[first - 'a'].push_back({i,0});
        }

        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            int ind = s[i]-'a';
            auto curr = move(wait[ind]);
            for(auto [wordIndex, pos] : curr){
                pos++;
                if(pos == words[wordIndex].size())ans++;
                else{
                    char c = words[wordIndex][pos];
                    wait[c-'a'].push_back({wordIndex,pos});
                }
            }
        }

        return ans;
    }
};