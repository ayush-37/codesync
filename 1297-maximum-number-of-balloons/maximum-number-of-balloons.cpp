class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> v(26,0);
        for(int i = 0; i < n; i++)v[text[i]-'a']++;
        int ans = INT_MAX;
        
        ans = min(ans,v['b'-'a']);
        ans = min(ans,v['a'-'a']);
        ans = min(ans,v['l'-'a']/2);
        ans = min(ans,v['o'-'a']/2);
        ans = min(ans,v['n'-'a']);

        return ans == INT_MAX?0:ans;
    }
};