class Solution {
public:
    void solve(int curr, int i, int noDig, int& tot, int& k, set<int>& ans){
        if(noDig == tot){
            ans.insert(curr);
            return;
        }

        int temp = curr*10;
        temp += i;
        if(i+k <= 9){
            solve(temp,i+k,noDig+1,tot,k,ans);
        }
        if(i-k >= 0){
            solve(temp,i-k,noDig+1,tot,k,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> ans;
        for(int i = 1; i <= 9; i++){
            solve(0,i,0,n,k,ans);
        }
        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};