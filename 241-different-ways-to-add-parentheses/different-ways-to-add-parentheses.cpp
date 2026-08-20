class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        // base case single digit or two digit number
        for(int i = 0; i < n; i++){
            if(isdigit(expression[i])){
                int x1 = expression[i]-'0';
                if(i+1 < n && isdigit(expression[i+1])){
                    int x2 = x1*10 + (expression[i+1]-'0');
                    dp[i][i+1].push_back(x2);
                }
                dp[i][i].push_back(x1);
            }
        }

        // Fill the dp table for all possible subexpressions
        for(int len = 3; len <= n; len++){
            for(int i = 0; i + len -1 < n; i++){
                int start = i;
                int end = i + len - 1;
                for(int j = start; j <= end; j++){
                    if(isdigit(expression[j]))continue;
                    // Try all possible positions to split the expression
                    vector<int> left = dp[start][j-1];
                    vector<int> right = dp[j+1][end];

                    // Compute results based on the operator at position 'split'
                    for(auto x: left){
                        for(auto y: right){
                            if(expression[j] == '+')dp[start][end].push_back(x + y);
                            else if(expression[j] == '-')dp[start][end].push_back(x - y);
                            else dp[start][end].push_back(x * y);
                        }
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};