class Solution {
public:
    int maxProduct(int n) {
        vector<int> v(10,0);
        int temp = n;
        while(temp){
            v[temp%10]++;
            temp/=10;
        }
        int ans = 1;
        for(int i = 9, cnt = 2; i >= 0 && cnt > 0; i--){
            if(v[i] != 0){
                int p = min(cnt,v[i]);
                ans = ans * (int)pow(i,p);
                cnt -= p;
            }
        }
        return ans;
    }
};