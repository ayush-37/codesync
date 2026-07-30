class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 1, n = word.size(), ans = 0;
        while(n > 0){
            ans += (cnt*min(8,n));
            n -= 8;
            cnt++;
        }
        return ans;
    }
};