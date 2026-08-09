class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> psum(n+1,0);

        for(int i = 1; i <= n; i++)psum[i] = psum[i-1] + nums[i-1];
        int ans = 0;
        const int MOD = 1e9+7;

        for(int i = 1; i <= n-2; i++){
            int left = psum[i];
            int l = i+1;
            int s = i+1, e = n-1;
            while(s <= e){
                int m = s + (e-s)/2;
                int mid = psum[m]-psum[i];
                int right = psum[n]-psum[m];
                if(mid >= left){
                    l = m;
                    e = m-1;
                }
                else s = m+1;
            }
            int r = l;
            s= l+1, e = n-1;
            while(s <= e){
                int m = s + (e-s)/2;
                int mid = psum[m]-psum[i];
                int right = psum[n]-psum[m];
                if(right >= mid){
                    r = m;
                    s = m+1;
                }
                else e = m-1;
            }
            int mid = psum[l]-psum[i];
            int right = psum[n]-psum[r];
            if(mid >= left && right >= mid)ans = (ans + r - l + 1)%MOD;
        }
        return ans;
    }
};