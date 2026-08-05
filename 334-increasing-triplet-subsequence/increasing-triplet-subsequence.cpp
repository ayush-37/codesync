class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> greater(n,INT_MIN);
        for(int i = n-2; i >= 0; i--){
            greater[i] = max(greater[i+1],nums[i+1]);
        }

        // for(auto x: greater)cout<<x<<" ";
        // cout<<endl;

        int mini = nums[0];
        // cout<<mini<<" ";
        for(int i = 1; i < n; i++){
            if(mini < nums[i] && nums[i] < greater[i])return true;
            mini = min(mini,nums[i]);
            // cout<<mini<<" ";
        }
        return false;
    }
};