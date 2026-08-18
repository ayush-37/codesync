class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n,1);
        vector<int> cnt(n,1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(len[j]+1 > len[i]){
                        len[i] = len[j]+1;
                        cnt[i] = 0;
                    }
                    if(len[j] + 1 == len[i])cnt[i] += cnt[j];
                }
            }
        }
        int maxi = *max_element(len.begin(),len.end());
        int res = 0;
        for(int i = 0; i < n; i++){
            if(len[i] == maxi)res += cnt[i];
        }

        return res;
    }
};