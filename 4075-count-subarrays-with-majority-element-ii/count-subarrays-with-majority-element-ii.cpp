class Solution {
public:
    long long mergeSort(vector<int>& arr, int s, int e){
        if(s >= e)return 0;
        long long cnt = 0;
        int mid = s + (e-s)/2;
        cnt += mergeSort(arr,s,mid);
        cnt += mergeSort(arr,mid+1,e);

        int j = mid+1;
        for(int i = s; i <= mid; i++){
            while(j <= e && arr[j] <= arr[i])j++;
            cnt += e-j+1;
        }

        vector<int> temp;
        int i = s;
        j = mid+1;
        while(i <= mid && j <= e){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= e){
            temp.push_back(arr[j]);
            j++;
        }

        for(int i = 0; i < temp.size(); i++)arr[i+s] = temp[i];
        return cnt;
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> psum(n+1,0);
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                psum[i+1] = psum[i]+1;
            }
            else{
                psum[i+1] = psum[i]-1;
            }
        }

        long long ans = mergeSort(psum,0,n);
        return ans;
    }
};