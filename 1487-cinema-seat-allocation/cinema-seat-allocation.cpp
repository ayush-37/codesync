class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int row = 1, cnt = 0;
        sort(reservedSeats.begin(), reservedSeats.end());
        vector<int> pref(11,0);
        int curr = reservedSeats[0][0], i = 0;
        while(i < reservedSeats.size()){
            if(reservedSeats[i][0] != curr){
                row++;
                for(int j = 1; j <= 10; j++){
                    pref[j] = pref[j-1] + pref[j];
                }
                if(pref[5]-pref[1] == 0){
                    cnt++;
                    if(pref[9]-pref[5] == 0)cnt++;
                }
                else{
                    if(pref[7] - pref[3] == 0)cnt++;
                    else if(pref[9]-pref[5] == 0)cnt++;
                }

                for(int j = 0; j < 11; j++)pref[j] = 0;
                pref[reservedSeats[i][1]] = 1;
                curr = reservedSeats[i][0];

            }
            else{
                pref[reservedSeats[i][1]] = 1;
            }
            i++;
        }
        for(int j = 1; j <= 10; j++){
            pref[j] = pref[j-1] + pref[j];
        }
        if(pref[5]-pref[1] == 0){
            cnt++;
            if(pref[9]-pref[5] == 0)cnt++;
        }
        else{
            if(pref[7] - pref[3] == 0)cnt++;
            else if(pref[9]-pref[5] == 0)cnt++;
        }
        return cnt + 2*(n-row);
    }
};