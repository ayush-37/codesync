class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        int cnt = 0;
        unordered_map<int ,int> mpa,mpb;
        for(int i = 0; i < n; i++){
            mpa[A[i]]++;
            if(mpb.count(A[i]))cnt++;
            if(mpa.count(B[i]))cnt++;
            mpb[B[i]]++;
            ans[i] = cnt;
        }
        return ans;
    }
};