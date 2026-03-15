class Solution {
public:
    int mergeSort(int s, int e, vector<int>& nums){
        if(s >= e)return 0;

        int mid = s + (e-s)/2;
        int cnt = 0;
        cnt += mergeSort(s,mid,nums);
        cnt += mergeSort(mid+1,e,nums);

        int j = mid+1;
        for(int i = s; i <= mid; i++){
            while(j <= e && (long long)nums[i] > nums[j]*2LL)j++;
            cnt += j-(mid+1);
        }

        vector<int> temp;
        int i = s;
        j = mid+1;
        while(i <= mid && j <= e){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= e){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = s; i <= e; i++){
            nums[i] = temp[i-s];
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0,n-1,nums);
    }
};