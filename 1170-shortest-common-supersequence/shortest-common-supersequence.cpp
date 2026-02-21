class Solution {
private:
string longestCommonSubsequence(string text1, string text2){
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m + 1; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i = n, j = m;
        string ans = "";
        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1])i--;
                else j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string s = longestCommonSubsequence(str1, str2);
        int n = str1.size(), m = str2.size(), sl = s.size();
        int i = 0, j = 0, k = 0;
        string ans = "";
        while(sl--){
            while(i < n && str1[i] != s[k]){
                ans.push_back(str1[i]);
                i++;
            }
            while(j < m && str2[j] != s[k]){
                ans.push_back(str2[j]);
                j++;
            }

            ans.push_back(s[k]);
            k++,i++,j++;
        }
        while(i < n){
            ans.push_back(str1[i]);
            i++;
        }
        while(j < m){
            ans.push_back(str2[j]);
            j++;
        }
        return ans;
    }
};