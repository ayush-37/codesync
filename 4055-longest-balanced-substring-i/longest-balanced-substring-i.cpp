class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> v(26);
            for(int j = i; j < n; j++){
                v[s[j]-'a']++;
                bool flag = true;
                int val = -1;
                for(int k = 0; k < 26 && flag; k++){
                    if(v[k] != 0){
                        if(val == -1)val = v[k];
                        else {
                            if(val != v[k]){
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                if(flag) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};