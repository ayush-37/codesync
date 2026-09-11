class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(auto x: digits)freq[x]++;

        int cnt = 0;
        for(int i = 0; i <= 8; i+=2){
            if(freq[i] == 0)continue;
            freq[i]--;
            for(int j = 1; j <= 9; j++){
                if(freq[j] == 0)continue;
                freq[j]--;
                for(int k = 0; k <= 9; k++){
                    if(freq[k] != 0)cnt++;
                }
                freq[j]++;
            }
            freq[i]++;
        }

        return cnt;
    }
};