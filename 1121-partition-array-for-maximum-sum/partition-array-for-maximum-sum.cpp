class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans(n+1,0);
        for(int i = 0; i < n; i++){
            int temp = 0, maxi = 0;
            for(int j = 0; j < k; j++){
                int curr = max(i-j,0);
                maxi = max(maxi, arr[curr]);
                int len = i - curr + 1;
                temp = max(temp, maxi * len + ans[curr]);
            }
            ans[i+1] = temp;
            cout<<ans[i+1]<<" ";
        }
        return ans[n];
    }
};