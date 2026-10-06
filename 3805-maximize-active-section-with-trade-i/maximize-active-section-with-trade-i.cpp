class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = 0;
        vector<int> zero;
        int i = 0;
        while(i < s.size()){
            char x = s[i];
            if(x == '0'){
                int cnt0 = 0;
                while(i < s.size() && s[i] == '0')i++, cnt0++;
                zero.push_back(cnt0);
            }
            else{
                i++;
                cnt1++;
            }
        }

        if(zero.empty())return cnt1;
        if(zero.size() < 2)return cnt1;

        int last = zero[0], temp = zero[0];
        for(int i = 1; i < zero.size(); i++){
            temp = max(temp, last + zero[i]);
            last = zero[i];
        }

        return temp + cnt1;
        
    }
};