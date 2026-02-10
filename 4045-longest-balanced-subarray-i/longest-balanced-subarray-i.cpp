class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int cnt = 0;
        set<int> odd,eve;
        for(int i = 0; i < nums.size()-1; i++){
            odd.clear();
            eve.clear();
            if(nums[i]%2)odd.insert(nums[i]);
            else eve.insert(nums[i]);
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j]%2)odd.insert(nums[j]);
                else eve.insert(nums[j]);
                if(odd.size() == eve.size())cnt = max(cnt,j-i+1);
            }    
        }
        return cnt;
    }
};