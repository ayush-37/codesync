class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for(int i = 0; i < nums.size(); i++){
            if(st.empty())st.push(i);
            else{
                if(nums[i] < nums[st.top()])st.push(i);
            }
        }

        int ans = 0, i = nums.size()-1;

        while(!st.empty() && i >= 0){
            if(nums[i] >= nums[st.top()]){
                ans = max(ans, i - st.top());
                st.pop();
            }
            else{
                i--;
            }
        }
        return ans;
    }
};