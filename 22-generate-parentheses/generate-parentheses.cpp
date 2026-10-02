class Solution {
public:
    vector<string> ans;
    void generate(int n, int o, int c, string temp){
        if(o == n && c == n){
            ans.push_back(temp);
            return;
        }

        if(o < n){
            temp.push_back('(');
            generate(n,o+1,c,temp);
            temp.pop_back();
        }

        if(c < o){
            temp.push_back(')');
            generate(n, o, c+1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        generate(n,0,0,"");
        return ans;
    }
};