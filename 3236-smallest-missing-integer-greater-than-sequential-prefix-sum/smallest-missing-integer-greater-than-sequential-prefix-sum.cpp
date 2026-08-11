class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0]+1;
        int x = nums[0], sum = x;
        bool isSeq = true;
        for(int i = 1; i < n; i++){
            if(nums[i] != x+1){
                isSeq = false;
                break;
            }
            x = nums[i];
            sum += x;
        }
        if(isSeq)return sum;
        sort(nums.begin(),nums.end());
        auto v = unique(nums.begin(),nums.end());
        nums.erase(v,nums.end());
        auto itr = lower_bound(nums.begin(),nums.end(), sum);
        if(itr == nums.end() || *itr != sum)return sum;
        int ind = (itr-nums.begin())+1;
        int y = sum;
        while(ind < n && nums[ind] == y+1){
            y = nums[ind];
            ind++;
        }
        return y+1;
    }
};