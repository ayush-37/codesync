class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i = 0; i < word.size(); i++){
            freq[word[i]-'a']++;
        }

        vector<pair<int,int>> maxClick;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                maxClick.push_back({freq[i],i});
            }
        }

        sort(maxClick.begin(),maxClick.end(),greater<pair<int,int>>());
        vector<int> click(26,0);

        int cnt = 1;
        for(int i = 0; i < maxClick.size(); i++){
            auto [f,c] = maxClick[i];
            click[c] = cnt;
            if(i+1 == 8*cnt)cnt++;
        }

        int ans = 0;
        for(int i = 0; i < maxClick.size(); i++){
            auto [f,c] = maxClick[i];
            ans += (click[c]*f);
        }
        return ans;
    }
};