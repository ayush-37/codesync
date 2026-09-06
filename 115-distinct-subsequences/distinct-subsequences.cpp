class Solution {
public:
    int n , m;
    vector<vector<int>> memo;
    int numDistinct(string s, string t) {
        n = s.size(), m = t.size();
        memo.resize(n,vector<int>(m,-1));

        return solve(0,0,s,t);
    }
    int solve(int i, int j, string& s, string& t){
        if(j == m){
            return 1;
        }

        if(i == n)return 0;

        if(memo[i][j] != -1)return memo[i][j];

        int tot = 0;
        
        tot += solve(i+1, j, s, t);
        if(s[i] == t[j])tot += solve(i+1, j+1, s, t);

        return memo[i][j] = tot;
    }
};