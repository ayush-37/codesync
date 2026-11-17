class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0;
        int odd = 0, even = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum%2)odd++;
        }
        even = n - odd;
        if(odd == 0)return 0;
        const int MOD = 1e9 + 7;
        int ans = 0;
        for(int i = 0; i < n; i++){
            // cout<<odd<<" "<<even<<endl;
            ans = (ans + odd)%MOD;
            if(arr[i]%2){
                odd--;
                swap(odd,even);
            }
            else{
                even--;
            }
        }

        return ans;
    }
};