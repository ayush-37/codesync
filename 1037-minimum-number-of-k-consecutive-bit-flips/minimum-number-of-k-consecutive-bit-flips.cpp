class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        deque<int> dq;
        for(int i = 0; i < n; i++){
            while(!dq.empty() && i > dq.front() + k - 1)dq.pop_front();
            if((nums[i] + dq.size()) % 2 == 0){
                if(i + k > n)return -1;
                cnt++;
                dq.push_back(i);
            }
        }
        return cnt;
    }
};