class Solution {
public:
    vector<string> posState;
    vector<char> c{'R', 'G', 'B'};
    vector<vector<int>> memo;
    const int MOD = 1e9+7;
    int row, col;
    void generateStates(int i, string s){
        if(i == 0){
            posState.push_back(s);
            return;
        }

        for(int j = 0; j < 3; j++){
            if(!s.empty() && s.back() == c[j])continue;
            s.push_back(c[j]);
            generateStates(i-1, s);
            s.pop_back();
        }
    }

    int numOfWays(int n) {
        row = 3, col = n;
        string temp = "";
        generateStates(row, temp);

        int x = posState.size();
        memo.assign(col+1, vector<int>(x,-1));

        int ans = 0;
        for(int i = 0; i < posState.size(); i++){
            ans = (ans + solve(col-1, i)) % MOD;
        }

        return ans;
    }

    int solve(int n, int i){
        if(n == 0)return 1;
        if(memo[n][i] != -1)return memo[n][i];

        int tot = 0;
        for(int j = 0; j < posState.size(); j++){
            bool valid = true;
            for(int k = 0; k < row; k++){
                if(posState[i][k] == posState[j][k]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                tot = (tot + solve(n-1, j)) % MOD;
            }
        }

        return memo[n][i] = tot;
    }
};