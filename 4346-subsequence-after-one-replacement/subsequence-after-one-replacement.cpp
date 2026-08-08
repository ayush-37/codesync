class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<int> pre(n+1,-1);

        for(int i = 1; i <= n; i++){
            int start = pre[i-1] + 1;
            while(start < m && s[i-1] != t[start])start++;
            pre[i] = start;
        }

        if(pre[n] < m)return true;

        vector<int> suf(n+1,m);
        for(int i = n-1; i >= 0; i--){
            int start = suf[i+1]-1;
            while(start >= 0 && s[i] != t[start])start--;
            suf[i] = start;
        }

        for(int i = 0; i < n; i++){
            if(pre[i] + 1 < suf[i+1])return true;
        }
        return false;
    }
};