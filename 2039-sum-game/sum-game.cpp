class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left = 0, right = 0, l = 0, r = 0;
        for(int i = 0; i < n; i++){
            if(i < n/2){
                if(num[i] == '?')l++;
                else left += (num[i]-'0');
            }
            else{
                if(num[i] == '?')r++;
                else right += (num[i]-'0');
            }
        }

        if((l+r) % 2)return true;
        else{
            return left - right != (r-l)/2 * 9;
        }
    }
};