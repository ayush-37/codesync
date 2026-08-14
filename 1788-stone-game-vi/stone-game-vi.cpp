class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> ai_bi(n,0);
        int totB = 0;
        for(int i = 0; i < n; i++){
            ai_bi[i] = aliceValues[i] + bobValues[i];
            totB += bobValues[i];
        }

        sort(ai_bi.begin(),ai_bi.end(),greater<int>());
        int alice = 0;
        for(int i = 0; i < n; i+=2){
            alice += ai_bi[i];
        }

        if(alice - totB > 0)return 1;
        else if(alice - totB == 0)return 0;
        else return -1;
    }
};