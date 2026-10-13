class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        auto cmp = [&](int& a, int &b){
            return abs(a) > abs(b);
        };
        sort(nums.begin(), nums.end(), cmp);

        int n = nums.size(), m = (n+1)/2;
        long long sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            if(i < m)sum1 += (1LL*nums[i]*nums[i]);
            else sum2 += (1LL*nums[i]*nums[i]);
        }

        return sum1 - sum2;
    }
};