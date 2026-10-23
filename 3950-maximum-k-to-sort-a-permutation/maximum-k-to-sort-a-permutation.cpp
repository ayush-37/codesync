class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> freq(32,0);
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i){
                cnt++;
                for(int j = 0; j < 32; j++){
                    if(nums[i] & (1 << j))freq[j]++;
                }
            }
        }

        if(cnt == 0)return 0;
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(freq[i] == cnt)ans |= (1<<i);
        }
        return ans;
    }
};