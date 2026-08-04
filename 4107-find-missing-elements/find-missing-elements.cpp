class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        vector<int> v(101,0);
        for(int i = 0; i < nums.size(); i++)v[nums[i]]++;

        vector<int> ans;
        for(int i = mini; i <= maxi; i++)if(v[i] == 0)ans.push_back(i);
        return ans;
    }
};