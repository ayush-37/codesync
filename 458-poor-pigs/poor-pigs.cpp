class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1)return 0;
        
        int totTrials = (minutesToTest / minutesToDie),check = totTrials + 1, temp = check;

        int cnt = 1;
        while(buckets > temp){
            temp *= check;
            cnt++;
        }

        return cnt;
    }
};