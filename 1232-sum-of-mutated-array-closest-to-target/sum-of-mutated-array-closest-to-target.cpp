class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> pref(n+1,0);
        for(int i = 1; i <= n; i++)pref[i] = pref[i-1] + arr[i-1];

        auto getSum = [&](int x){
            auto ind = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
            int sum = pref[ind] + (n-ind)*x;
            return sum;
        };

        int s = 0, e = arr.back();
        while(s <= e){
            int mid = s + (e-s)/2;
            int sum = getSum(mid);
            if(sum < target){
                s = mid+1;
            }
            else e = mid-1;
        }
        
        int sumS = getSum(s);
        int sumE = getSum(e);

        if(abs(target-sumS) < abs(target-sumE))return s;
        else return e;
    }
};