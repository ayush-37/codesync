class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long s = 1, e = maxSum;
        long long mid, ans = 0;
        maxSum = maxSum*1LL;
        while(s <= e){
            mid = s + (e-s)/2;

            long long s1 = solve(mid,index+1);
            long long s2 = solve(mid,n-index);

            if(s1 + s2 - mid <= maxSum){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }

        return (int)ans;
    }

    long long solve(long long x, long long sp){
        if(sp >= x){
            return (x*(x+1))/2 + (sp-x);
        }
        else{
            long long y = x-sp;
            return (x*(x+1))/2 - (y*(y+1))/2;
        }
    }
};