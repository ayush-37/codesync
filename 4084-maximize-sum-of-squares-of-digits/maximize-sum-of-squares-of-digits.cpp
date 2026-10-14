class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int maxi = 9 * num;
        if(sum > maxi)return "";

        int cnt = 0;
        string ans = "";
        while(num--){
            for(int j = 9; j >= 0; j--){
                if(cnt + j <= sum){
                    ans.push_back('0' + j);
                    cnt += j;
                    break;
                }
            }
        }

        return ans;
    }
};