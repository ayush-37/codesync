class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> v(1e6+2,0);
        v[0] = 1, v[1] = 1;
        for(int i = 2; i < 1e6+2; i++){
            if(v[i])continue;
            for(int j = i*2; j < 1e6+2; j += i)v[j] = 1;
        }

        int cnt = 0;
        for(int i = left; i <= right; i++){
            int x = __builtin_popcount(i);
            if(v[x] == 0)cnt++;
        }
        return cnt;
    }
};