class Solution {
public:
    int minPartitions(string n) {
        vector<int> v(10);
        for(int i = 0; i < n.size(); i++){
            v[n[i]-'0'] = 1;
        }
        int ans = 0;
        for(int i = 9; i >= 0; i--){
            if(v[i]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};