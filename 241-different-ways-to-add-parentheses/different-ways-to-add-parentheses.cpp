/*
Time complexity: O(n⋅2^n)

For each sub-expression, we iterate through the string to identify the operators, which takes O(n) time. However, the key aspect is the recursive combination of results from the left and right sub-expressions. The number of results grows exponentially because each sub-expression produces multiple results, and combining these results takes O(k×l), where k and l are the numbers of results from the left and right sub-problems, respectively.

There were some suggestions to model the number of results using Catalan numbers which we deemed as incorrect. Catalan numbers apply when counting distinct ways to fully parenthesize an expression or structure. In this problem, however, we're not just counting valid ways to split the expression but also calculating and combining all possible results. This introduces exponential growth in the number of possible results, not the polynomial growth typical of Catalan numbers. The number of combinations grows exponentially with the depth of recursive splitting, which means the overall complexity is driven by the exponential growth in results.

Thus, the time complexity of the algorithm is O(n⋅2 
n
 ), where the O(2 
n
 ) factor reflects the exponential growth in the number of ways to combine results from sub-expressions.

Space complexity: O(2 
n
 )

The algorithm stores the intermediate results at each step. Since the total number of results can be equal to the O(2 
n
 ), the space complexity of the algorithm is O(2 
n
 ).

*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> ans;
        // Base case: if the string is empty, return an empty list
        if (expression.length() == 0) return ans;

        // Base case: if the string is a single character, treat it as a number
        // and return it
        if (expression.length() == 1) {
            ans.push_back(stoi(expression));
            return ans;
        }

        // If the string has only two characters and the first character is a
        // digit, parse it as a number
        if (expression.length() == 2 && isdigit(expression[0])) {
            ans.push_back(stoi(expression));
            return ans;
        }

        for(int i = 0; i < n; i++){
            char c = expression[i];
            if(c >= '0' && c <= '9')continue;
            
            vector<int> left = diffWaysToCompute(expression.substr(0,i));
            vector<int> right = diffWaysToCompute(expression.substr(i+1));

            for(int x: left){
                for(int y: right){
                    if(c == '+')ans.push_back(x + y);
                    else if(c == '*')ans.push_back(x * y);
                    else ans.push_back(x - y);
                }
            }
        }
        return ans;
    }
};