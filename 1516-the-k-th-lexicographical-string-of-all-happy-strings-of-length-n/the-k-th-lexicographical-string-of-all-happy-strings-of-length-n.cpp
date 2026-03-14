class Solution {
public:
    string getHappyString(int n, int k) {
        int maxi = 1<<(n-1);
        unordered_map<char,vector<char>> mp;
        mp['a'] = {'b','c','x'};
        mp['b'] = {'a','c','x'};
        mp['c'] = {'a','b','x'};
        string s = "";
        if(k > 3*maxi)return s;

        int temp = k;
        if(temp <= maxi)s += 'a';
        else if(temp <= 2*maxi)s += 'b';
        else s += 'c';

        if((temp % maxi) != 0)temp%=maxi;
        else temp = maxi;
        maxi /= 2;

        while(maxi){

            if(temp <= maxi)s += mp[s.back()][0];
            else s += mp[s.back()][1];

            if((temp % maxi) != 0)temp%=maxi;
            else temp = maxi;
            maxi/=2;
        }
        return s;
    }
};