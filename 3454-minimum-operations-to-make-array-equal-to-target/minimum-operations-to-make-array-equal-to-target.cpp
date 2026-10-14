class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0, prev = 0, n = nums.size();
        vector<int> diff(n,0);
        for(int i = 0; i < n; i++)diff[i] = target[i] - nums[i];

        for(auto curr: diff){
            if( 1LL * curr * prev < 0LL){
                ans += abs(curr);
            }
            else{
                if(abs(curr) > abs(prev))ans += abs(curr - prev);
            }
            prev = curr;
        }

        return ans;
    }
};