class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int last = 0, ans = 0;
        for(int i = 0; i < requests.size(); i++){
            ans += abs(requests[i] - last);
            last = requests[i];
        }
        return ans;
    }
};