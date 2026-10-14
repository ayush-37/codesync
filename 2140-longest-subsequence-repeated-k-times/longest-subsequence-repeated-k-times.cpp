class Solution {
public:
    vector<string> words;
    vector<char> valid;
    vector<int> useFreq;
    int maxL;
    string curr;

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int> freq(26,0);
        for(auto x: s)freq[x-'a']++;

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                valid.push_back('a' + i);
            }
        }

        maxL = n/k;
        useFreq.assign(26,0);
        for(auto x: valid){
            useFreq[x-'a'] = freq[x-'a']/k;
        }

        backtrack();

        if(words.empty())return "";
        sort(words.begin(), words.end(), [](const string& a,const string& b){
            if (a.size() != b.size()) {
                return a.size() > b.size();
            }
            return a > b;
        });

        auto check = [&](string& a, string& b){
            int i = 0, j = 0;
            int temp = k;
            while(i < a.size() && temp){
                if(a[i] == b[j]){
                    i++, j++;
                }
                else i++;

                if(j == b.size()){
                    temp -= 1;
                    j = 0;
                }
            }

            return (temp == 0);
            
        };

        string ans = "";
        for(auto str: words){
            bool is = check(s, str);
            if(is){
                ans = str;
                break;
            }
        }

        return ans;
    }

    void backtrack() {
        // Every non-empty prefix is a valid word
        if (!curr.empty()) {
            words.push_back(curr);
        }

        if (curr.size() == maxL) return;

        for (int i = 0; i < valid.size(); i++) {
            if (useFreq[valid[i] - 'a'] == 0) continue;

            // Choose character i
            curr.push_back(valid[i]);
            useFreq[valid[i] - 'a']--;

            backtrack();

            // Undo choice
            useFreq[valid[i] - 'a']++;
            curr.pop_back();
        }
    }
};