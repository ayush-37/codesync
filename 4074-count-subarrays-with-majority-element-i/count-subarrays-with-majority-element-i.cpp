class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        for(int i = 0; i < n; i++){
            if(nums[i] == target)freq[i+1] = freq[i]+1;
            else freq[i+1] = freq[i];
        }

        int ans = 0;
        for(int i = 0; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(freq[j]-freq[i] > (j-i)/2){
                    ans++;
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
        return ans;
    }
};