class Solution {
public:
    #define ll long long
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1 + cost2 <= costBoth){
            return 1LL*cost1*need1 + 1LL*cost2*need2;
        }
        else{
            int mini = min(need1, need2);
            need1 -= mini, need2 -= mini;
            ll tot = 1LL*mini*costBoth;
            if(need1 != 0){
                if(cost1 <= costBoth){
                    tot += 1LL*cost1*need1;
                }
                else{
                    tot += 1LL*costBoth*need1;
                }
            }
            else{
                if(cost2 <= costBoth){
                    tot += 1LL*cost2*need2;
                }
                else{
                    tot += 1LL*costBoth*need2;
                }
            }
            return tot;
        }
    }
};