class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0] = 1;
        // cout<<arr[0]<<" ";
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i-1]+1)arr[i] = arr[i-1]+1;
            // cout<<arr[i]<<" ";
        }
        // cout<<endl;
        return arr.back();
    }
};