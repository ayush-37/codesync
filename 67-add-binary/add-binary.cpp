class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0, i = a.size()-1, j = b.size()-1;
        while(i >= 0 && j >= 0){
            if(a[i] == '1' && b[j] == '1'){
                ans.push_back('0'+carry);
                carry = 1;
            }
            else{
                if(a[i] == '0' && b[j] == '0'){
                    ans.push_back('0'+carry);
                    carry = 0;
                }
                else{
                    if(carry == 0){
                        ans.push_back('1');
                        carry = 0;
                    }
                    else {
                        ans.push_back('0');
                        carry = 1;
                    }
                }
            }

            i--,j--;
        }
        while(i >= 0){
            if(a[i] == '1'){
                if(carry == 0){
                    ans.push_back('1');
                    carry = 0;
                }
                else{
                    ans.push_back('0');
                    carry = 1;
                }
            }
            else{
                ans.push_back('0'+carry);
                carry = 0;
            }
            i--;
        }
        while(j >= 0){
            if(b[j] == '1'){
                if(carry == 0){
                    ans.push_back('1');
                    carry = 0;
                }
                else{
                    ans.push_back('0');
                    carry = 1;
                }
            }
            else{
                ans.push_back('0'+carry);
                carry = 0;
            }
            j--;
        }
        if(carry)ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};