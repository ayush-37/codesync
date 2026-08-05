class Solution {
public:
    using ll = long long;
    int minimumSize(vector<int>& nums, int maxOperations) {
        ll n = nums.size(), s = 1, e = *max_element(nums.begin(),nums.end()), ans = INT_MAX;
        while(s <= e){
            ll maxi = s + (e-s)/2, noOfBags = 0;
            for(int i = 0 ; i < n; i++){
                if(nums[i] > maxi){
                    noOfBags += (nums[i]/maxi) - (nums[i]%maxi == 0);
                }
            }

            if(noOfBags <= maxOperations){
                ans = maxi;
                e = maxi - 1;
            }
            else s = maxi+1;
        }

        return ans;
    }
};