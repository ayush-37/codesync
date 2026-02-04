class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dec;
        long long l = 0, sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i-1] <= nums[i]){
                dec.push_back({l,i-1,sum});
                sum = 0;
                l = i;
            }
            sum+=nums[i];
        }
        dec.push_back({l,n-1,sum});


        vector<long long> end(n);
        for(int i = 0; i < n; i++)end[i] = nums[i];
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1] && end[i-1] > 0)end[i] += end[i-1];
        }
        vector<long long> start(n);
        for(int i = 0; i < n; i++)start[i] = nums[i];
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1] && start[i+1] > 0)start[i] += start[i+1];
        }

        long long ans = LLONG_MIN;
        for(auto v: dec){
            long long p = v[0], q = v[1], sum = v[2];
            if(p > 0 && nums[p-1] < nums[p] &&
               q < n - 1 && nums[q] < nums[q + 1] &&
               p < q){
                ans = max(ans,end[p-1] + sum + start[q+1]);
            }
        }
        return ans;
    }
};
