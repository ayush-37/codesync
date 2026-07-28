class Solution {
public:
    using ll = long long;
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1e9+7, n = nums.size();
        vector<ll> psum(n+1,0);

        for(int i = 1; i <= n; i++)psum[i] = psum[i-1] + nums[i-1];

        stack<int> st;
        vector<int> left(n,0), right(n,0);
        
        st.push(0);
        for(int i = 1; i < n; i++){
            int ind = i;
            while(!st.empty() && nums[i] <= nums[st.top()]){
                ind = left[st.top()];
                st.pop();
            }
            left[i] = ind;
            st.push(i);
        }
        while(!st.empty())st.pop();

        right[n-1] = n;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--){
            int ind = i+1;
            while(!st.empty() && nums[i] <= nums[st.top()]){
                ind = right[st.top()];
                st.pop();
            }
            right[i] = ind;
            st.push(i);
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans , (psum[right[i]] - psum[left[i]])*nums[i]);
        }
        return (int)(ans%mod);
    }
};