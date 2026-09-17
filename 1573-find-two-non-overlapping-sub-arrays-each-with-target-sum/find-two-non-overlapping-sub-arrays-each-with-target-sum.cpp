class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = 0, r = 0, sum = 0, n = arr.size(), ans = n+1;
        vector<int> best(n+1,n);
        // best[i]=minimum length of a target-sum subarray completely before i

        while(r < n){
            sum += arr[r];
            while(sum > target){
                sum -= arr[l];
                l++;
            }
            best[r+1] = best[r]; // I don't find a new valid subarray ending at r, the best answer so far doesn't change.
            if(sum == target){
                int len = r - l + 1;
                ans = min(ans, len + best[l]);
                // best[l] We need another subarray that is completely before it.
                best[r+1] = min(best[r], len);
            }
            r++;
        }

        if(ans == n+1)return -1;
        else return ans;
    }
};