class Solution {
    long long findN(long long x, long long sn){

        long double root = (long double)x * x + (long double)8 * x * sn;
        long double num = sqrt(root);

        return (long long)((-x + num) / (2 * x));
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long s = 1, e = LLONG_MAX;
        long long ans = e, mid;
        while(s <= e){
            mid = s + (e-s)/2;
            long long sum = 0;
            for(int i = 0; i < workerTimes.size(); i++){
                sum += findN(workerTimes[i],mid);
                if(sum > mountainHeight)break;
            }
            if(sum >= mountainHeight){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};