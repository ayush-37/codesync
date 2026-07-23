class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)return n;
        else{
            int t = 1;
            while(t <= n)t = t << 1;
            return t;
        }
        
    }
};