class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51, 0);
        for(auto x: nums)freq[x]++;
        if(k == 1){
            for(int i = 50; i >= 0; i--){
                if(freq[i] == 1)return i;
            }
            return -1;
        }
        else if(k == n){
            return *max_element(nums.begin(),nums.end());
        }
        else{
            if(freq[nums[0]] == 1 && freq[nums.back()] == 1){
                return max(nums[0],nums.back());
            }
            else if(freq[nums[0]] == 1)return nums[0];
            else if(freq[nums.back()] == 1)return nums.back();
            else return -1;
        }
    }
};