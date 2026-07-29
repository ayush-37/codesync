class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size(), big = nums[0]; 
        vector<int> small(n,0);

        small[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            small[i] = min(small[i+1],nums[i]);
        }

        int ans = 0;
        for(int i = 1; i < n; i++){
            if(big <= small[i]){
                ans = i;
                break;
            }
            big = max(big,nums[i]);
        }
        return ans;
    }
};