class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)return n;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int mx = 0, mn = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi)mx = i+1;
            if(nums[i] == mini)mn = i+1;
        }

        int a = min(mx,mn), b = max(mx,mn);
        return min({b, n-a+1, a + n - b + 1});


    }
};