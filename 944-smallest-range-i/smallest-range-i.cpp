class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        stack<pair<int,int>> st;
        for(int i = 0; i < n; i++){
            if(st.empty())st.push({nums[i]-k, nums[i]+k});
            else{
                int l = nums[i]-k, r = nums[i]+k;
                while(!st.empty() && st.top().second >= nums[i] - k){
                    
                    l = max(st.top().first,nums[i]-k);
                    r = min(st.top().second,nums[i]+k);
                    st.pop();
                }
                st.push({l,r});
            }
            // cout<<st.top().first<<" "<<st.top().second<<endl;
        }

        int mini1 , maxi1, mini2, maxi2;
        if(st.size() == 1)return 0;
        else{
            mini2 = st.top().first, maxi2 = st.top().second;
            while(!st.empty()){
                st.pop();
                if(st.size() == 1){
                    mini1 = st.top().first, maxi1 = st.top().second;
                }
            }

            return mini2-maxi1;
        }
    }
};