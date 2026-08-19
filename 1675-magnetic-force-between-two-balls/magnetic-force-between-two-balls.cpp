class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size(), low = 1, high = position[n-1] - position[0];
        int ans;
        while(low <= high){
            int mid = low + (high-low)/2;
            int cnt = 1, l = 0;
            for(int r = 1; r < n && cnt < m; r++){
                if(position[r] - position[l] >= mid){
                    cnt++;
                    l = r;
                }
            }
            if(cnt == m){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};