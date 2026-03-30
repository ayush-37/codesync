class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> odd(26,0), even(26,0);

        for(int i = 0; i < n; i++){
            if(i%2)odd[s1[i]-'a']++;
            else even[s1[i]-'a']++;
        }

        for(int i = 0; i < n; i++){
            if(i%2){
                odd[s2[i]-'a']--;
                if(odd[s2[i]-'a'] < 0)return false;
            }
            else{
                even[s2[i]-'a']--;
                if(even[s2[i]-'a'] < 0)return false;
            }
        }

        for(int i = 0; i < 26; i++){
            if(odd[i] != 0)return false;
            if(even[i] != 0)return false;
        }

        return true;

    }
};