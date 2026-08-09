class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        int n = s.size();
        for(int i = 0; i < n; i++){
            mp[s[i]].push_back(i);
        }

        int ans = 0;

        for(int i = 0; i < words.size(); i++){
            if (words[i].size() > s.size() || mp.find(words[i][0]) == mp.end())continue;

            int l = mp[words[i][0]][0];
            bool can = true;

            for(int j = 1; j < words[i].size(); j++){
                char c = words[i][j];
                if (mp.find(c) == mp.end()){
                    can = false;
                    break;
                }
                int ind = upper_bound(mp[c].begin(),mp[c].end(), l) - mp[c].begin();
                if(ind == mp[c].size()){
                    can = false;
                    break;
                }
                l = mp[c][ind];
            }
            if(can)ans++;
        }
        return ans;
    }
};