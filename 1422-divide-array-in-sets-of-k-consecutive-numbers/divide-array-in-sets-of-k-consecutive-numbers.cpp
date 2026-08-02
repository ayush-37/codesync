class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0)return false;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto x: nums)mp[x]++;

        auto last = unique(nums.begin(),nums.end());
        nums.erase(last,nums.end());

        // for(auto x: nums)cout<<x<<" ";
        // cout<<endl;
        // for(auto x: nums)cout<<mp[x]<<" ";
        // cout<<endl;

        int l = 0, r = 0, ans = 0;
        while(l < nums.size()){
            int temp = k, first = mp[nums[l]],st = l;
            int firstNonZero = 0;
            // cout<<l<<" "<<r<<" "<<first<<endl;
            while(temp--){
                // cout<<nums[r]<<" ";
                if(r == nums.size())return false;
                if((r != st) && nums[r]-1 != nums[r-1]){
                    return false;
                }
                else{
                    if(mp[nums[r]] < first)return false;

                    mp[nums[r]] -= first;

                    if(mp[nums[r]] == 0 && !firstNonZero){
                        // mp.erase(nums[r]);
                        l++;
                    }
                    else{
                        firstNonZero = 1;
                    }
                }
                r++;
            }
            // cout<<endl;
            r = l;
        }
        return !mp.empty();
        
    }
};