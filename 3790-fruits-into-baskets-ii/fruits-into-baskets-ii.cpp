class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ans = 0;
        vector<int> fill(n,0);
        for(int i = 0; i < n; i++){
            bool cannot = true;
            for(int j = 0; j < n; j++){
                if(fill[j] == 0 && baskets[j] >= fruits[i]){
                    fill[j] = fruits[i];
                    cannot = false;
                    break;
                }
            }
            if(cannot)ans++;
        }

        return ans;
    }
};