class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1,inc = -1;
        int l = 0, r = 1, n = arr.size();
        while(r < n){
            if(inc == -1){
                if(arr[r] > arr[r-1])inc = 1;
                else if(arr[r] < arr[r-1])inc = 0;
                else l++;
            }
            else{
                if(inc == 1){
                    if(arr[r] >= arr[r-1]){
                        ans = max(ans,r-l);
                        l = r-1;
                        if(arr[r] == arr[r-1])inc = -1,l++;
                    }
                    else inc = 0;
                }else{
                    if(arr[r] <= arr[r-1]){
                        ans = max(ans,r-l);
                        l = r-1;
                        if(arr[r] == arr[r-1])inc = -1,l++;
                    }
                    else inc = 1;
                }
            }
            r++;
        }
        return ans = max(ans,r-l);
    }
};