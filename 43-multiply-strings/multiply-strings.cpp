class Solution {
public:
    vector<vector<pair<int,int>>> mul;
    void helper(){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                int m = i*j;
                int d = m%10, c = m/10;
                mul[i][j] = {d,c};
            }
        }
    }
    string multiply(string num1, string num2) {
        if(num1.size() < num2.size())return multiply(num2,num1);
        if(num1 == "0" || num2 == "0")return "0";
        mul.resize(10,vector<pair<int,int>>(10));
        helper();

        string ans = "";
        string prev(num1.size()+1,'0');
        for(int j = num2.size()-1; j >= 0; j--){
            string curr = "0";
            int carry = 0;
            for(int i = num1.size()-1; i >= 0; i--){
                int id = num1[i] - '0', jd = num2[j] - '0';
                auto[d,c] = mul[id][jd];
                int nd = (d + carry) % 10;
                int nc = (d + carry) / 10 + c;
                char ch = '0' + nd;
                curr.push_back(ch);
                carry = nc;
            }
            if(carry > 0){
                curr += to_string(carry);
            }
            // cout<<curr<<endl;
            // cout<<prev<<endl;

            string addOp = add(curr, prev);
            // cout<<addOp<<endl<<endl;
            ans.push_back(addOp[0]);
            addOp.erase(0,1);
            prev = addOp;
        }
        ans += prev;
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        return ans;
    }

    string add(string a, string b){
        int n = a.size(), m = b.size(), i = 0, j = 0;
        int carry = 0;
        string ans = "";
        while(i < n && j < m){
            int ai = a[i] - '0', bj = b[j] - '0';
            int nd = (ai + bj + carry)%10;
            int nc = (ai + bj + carry)/10;

            ans.push_back('0' + nd);
            carry = nc;
            i++, j++;
        }

        while(i < n){
            int ai = a[i] - '0';
            int nd = (ai + carry)%10;
            int nc = (ai + carry)/10;

            ans.push_back('0' + nd);
            carry = nc;
            i++;
        }
        while(j < m){
            int bj = b[j] - '0';
            int nd = (bj + carry)%10;
            int nc = (bj + carry)/10;

            ans.push_back('0' + nd);
            carry = nc;
            j++;
        }

        if(carry != 0)ans += to_string(carry);
        return ans;
    }
};