class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mxi(n,0);
        mxi[0] = nums[0];
        for(int i = 1; i < n; i++)mxi[i] = max(nums[i],mxi[i-1]);
        vector<int> g;
        for(int i = 0;i < n; i++)g.push_back(gcd(mxi[i],nums[i]));
        sort(g.begin(),g.end());
        int i = 0, j = g.size()-1;
        long long ans = 0;
        while(i<j){
            ans += gcd(g[i],g[j]);
            i++;
            j--;
        }
        return ans;
    }
};