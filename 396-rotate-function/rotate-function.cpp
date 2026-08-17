class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0, n = nums.size(), ans = 0, fi = 0;
        for(long long i = 0; i < n; i++){
            fi += (i*nums[i]);
            sum += nums[i];
        }
        ans = fi;
        int i = 1;
        while(i < n){
            fi += sum;
            fi -= n*nums[n-i];
            ans = max(ans, fi);
            i++;
        }
        return ans;
    }
};