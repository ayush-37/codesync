class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0)temp.push_back(nums[i]);
        }

        int ind = k;
        int n = temp.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0)continue;
            else{
                ind %= n;
                nums[i] = temp[ind];
                ind++;
            }
        }
        return nums;
    }
};