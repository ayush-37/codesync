class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int s = 0, e = n-k;
        
        while(s < e){
            int mid = s + (e-s)/2;
            if(x-arr[mid] <= arr[mid+k] - x){
                e = mid;
            }
            else {
                s = mid+1;
            }
        }

        vector<int> res(arr.begin()+s, arr.begin()+s+k);
        return res;
    }
};