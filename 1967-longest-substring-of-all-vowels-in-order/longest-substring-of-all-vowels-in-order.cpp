class Solution {
public:
    int longestBeautifulSubstring(string word) {
        unordered_map<char,pair<char,char>> mp;
        mp['a'] = {'a','e'};
        mp['e'] = {'e','i'};
        mp['i'] = {'i','o'};
        mp['o'] = {'o','u'};
        mp['u'] = {'u','u'};

        int l = 0, r = 0;
        int ans = 0;
        char last = 'a', next = 'a';
        while(r < word.size()){
            if(word[r] == last){
               if(word[r] == 'a')next = 'e';
               else if(word[r] == 'u')ans = max(ans,r-l+1);
                r++;
            }
            else if(word[r] == next){
                if(word[r] == 'u')ans = max(ans,r-l+1);
                last = mp[word[r]].first, next = mp[word[r]].second;
                r++;
            }
            else{
                if(word[r] != 'a'){
                    last = 'a', next = 'a';
                    r++;
                    l = r;
                }
                else{
                    last = 'a', next = 'e';
                    l = r;
                    r++;
                }
            }
        }
        return ans;
    }
};