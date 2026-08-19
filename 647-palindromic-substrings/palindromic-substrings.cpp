class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = n;
        vector<vector<int>> v(n,vector<int>(n,0));
        for(int i = 0; i < n; i++)v[i][i] = 1;
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j]){
                    if(i+1 > j-1){
                        v[i][j] = 1;
                        ans++;
                    }
                    else if(v[i+1][j-1]){
                        v[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};