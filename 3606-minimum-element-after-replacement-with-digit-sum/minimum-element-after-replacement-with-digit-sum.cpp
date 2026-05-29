class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 50;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            int sum = 0;
            while(temp){
                sum += temp%10;
                temp/=10;
            }
            ans = min(ans,sum);
        }
        return ans;
    }
};