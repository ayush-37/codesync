class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0, n = nums.size();
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                int s = nums[i] + nums[j];
                int d = abs(nums[i]-nums[j]);
                // cout<<nums[i]<<" "<<nums[j]<<"  s- "<<s<<" d- "<<d<<"   ";
                int r = lower_bound(nums.begin()+j+1, nums.end(), s) - nums.begin();
                int l = upper_bound(nums.begin()+j+1, nums.end(), d) - nums.begin();
                // cout<<r<<" "<<l<<endl;
                ans += max(0,r-l);
            }
        }
        return ans;
    }
};