class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        int l = upper_bound(arr.begin(),arr.end(), x) - arr.begin() - 1, r = l+1;
        while(l >= 0 && r < n && ans.size() != k){
            if(abs(arr[l] - x) <= abs(arr[r]-x)){
                ans.push_back(arr[l]);
                l--;
            }
            else{
                ans.push_back(arr[r]);
                r++;
            }
        }
        while(l >= 0 && ans.size() != k){
            ans.push_back(arr[l]);
            l--;
        }
        while(r < n && ans.size() != k){
            ans.push_back(arr[r]);
            r++;
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};