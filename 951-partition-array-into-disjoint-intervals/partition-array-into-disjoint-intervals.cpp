class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> big(n,0), small(n,0);

        big[0] = nums[0];
        for(int i = 1; i < n; i++){
            big[i] = max(big[i-1],nums[i]);
        }

        small[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            small[i] = min(small[i+1],nums[i]);
        }

        int ans = 0;
        for(int i = 1; i < n; i++){
            if(big[i-1] <= small[i]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};