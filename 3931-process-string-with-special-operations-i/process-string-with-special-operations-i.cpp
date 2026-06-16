class Solution {
public:
    string reverse(string s){
        int n = s.size();
        int i = 0, j = n-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    string processStr(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                if(!ans.empty())ans.pop_back();
            }
            else if(s[i] == '%'){
                ans = reverse(ans);
            }
            else if(s[i] == '#')ans+=ans;
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};