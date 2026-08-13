class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)return arr[0];
        vector<int> left(n,0),right(n,0);
        int curr = 0, kad = INT_MIN;
        for(int i = 0; i < n; i++){
            curr = max(arr[i],curr+arr[i]);
            kad = max(kad,curr);
            left[i] = curr;
        }
        curr = 0;
        for(int i = n-1; i >= 0; i--){
            curr = max(arr[i],curr+arr[i]);
            right[i] = curr;
        }
        int ans = INT_MIN;
        for(int i = 1; i < n-1; i++)ans = max(ans,left[i-1] + right[i+1]);
        return max({right[1],left[n-2],ans,kad});
    }
};