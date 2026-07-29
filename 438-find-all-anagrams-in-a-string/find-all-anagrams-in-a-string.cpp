class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> freq(n+1,vector<int>(26,0));
        for(int i = 1; i <= n; i++){
            // cout<<i<<" - ";
            for(int j = 0; j < 26; j++){
                if(s[i-1] == 'a'+j)freq[i][j] = freq[i-1][j]+1;
                else freq[i][j] = freq[i-1][j];

                // cout<<freq[i][j]<<" ";
            }
            // cout<<endl;
        }

        vector<int> pfreq(26,0);
        for(int i = 0; i < m; i++)pfreq[p[i]-'a']++;

        vector<int> ans;
        for(int i = 0; i <= n-m; i++){
            int j = i+m;
            // cout<<i<<" "<<j<<endl;
            bool yes = true;
            for(int k = 0; k < 26; k++){
                int val = freq[j][k] - freq[i][k];
                if(val != pfreq[k]){
                    yes = false;
                    break;
                }
            }
            if(yes)ans.push_back(i);
        }
        return ans;
    }
};