class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int s = n+m-1;
        string ans(s,'a');
        vector<int> vis(s,0);

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = i; j < i+m; j++){
                    if(vis[j] == 0){
                        ans[j] = str2[j-i];
                        vis[j] = 1;
                    }
                    else{
                        if(ans[j] != str2[j-i])return "";
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                bool not_same = false;
                int idx = -1;
                for(int j = i+m-1; j >= i; j--){
                    if(ans[j] != str2[j-i]){
                        not_same = true;
                        break;
                    }

                    if(idx == -1 && vis[j] == 0){
                        idx = j;
                    }
                }
                if(not_same){
                    continue;
                }
                else if(idx != -1){
                    ans[idx] = 'b';
                }
                else return "";
            }
        }

        return ans;
    }
};