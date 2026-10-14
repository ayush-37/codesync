class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0, prev = 0;
        for(auto curr: target){
            if((prev > 0 && curr <= 0) || (prev < 0 && curr >= 0))ans += abs(curr);
            else{
                if(abs(curr) > abs(prev))ans += abs(curr-prev);
            }
            prev = curr;
        }

        return ans;
    }
};