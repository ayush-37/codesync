class Solution {
public:
    vector<vector<vector<int>>> mp;
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        mp.resize(n,vector<vector<int>>(n));
        vector<int> ans;
        ans = solve(expression, 0, n-1);
        return ans;
    }

    vector<int> solve(string s, int l, int r){
        if(l == r)return {s[l] - '0'};
        else if(l > r)return {0};
        else if(r-l == 1 && isdigit(s[l])){
            int tens = s[l] - '0';
            int ones = s[r] - '0';
            return {10 * tens + ones};
        }

        if(!mp[l][r].empty())return mp[l][r];

        vector<int> temp;
        for(int i = l; i <= r; i++){
            if(isdigit(s[i]))continue;

            vector<int> left = solve(s, l, i-1);
            vector<int> right = solve(s, i+1, r);

            for(auto x: left){
                for(auto y: right){
                    if(s[i] == '+')temp.push_back(x+y);
                    else if(s[i] == '-')temp.push_back(x-y);
                    else temp.push_back(x*y);
                }
            }
        }
        return mp[l][r] = temp;
    }
};