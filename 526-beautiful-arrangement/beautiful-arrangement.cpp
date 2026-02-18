class Solution {
private:
    void arrange(vector<int>& not_used, int ind, int& ans){
        if(ind > not_used.size()){
            ans++;
            return;
        }

        for(int i = 0; i < not_used.size(); i++){
            if((not_used[i] && ((i+1)%ind == 0 || ind%(i+1) == 0))){
                not_used[i] = 0;
                arrange(not_used,ind+1,ans);
                not_used[i] = 1;
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<int> not_used(n,1);
        int ans = 0;
        arrange(not_used,1,ans);
        return ans;
    }
};