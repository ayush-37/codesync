class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> prev(n,-1);
        vector<int> dp(n,1);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[j] % nums[i] == 0){
                    if(dp[j] < dp[i]+1){
                        dp[j] = dp[i]+1;
                        prev[j] = i;
                    }
                }
            }
        }

        int maxi = 0, ind = -1;
        for(int i = 0; i < n; i++){
            if(dp[i] > maxi){
                maxi = dp[i];
                ind = i;
            }
        }

        vector<int> ans;
        do{
            ans.push_back(nums[ind]);
            ind = prev[ind];
        }while(ind >= 0);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};