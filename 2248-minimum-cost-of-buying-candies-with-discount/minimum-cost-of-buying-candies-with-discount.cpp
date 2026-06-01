class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int sum = 0, flag = 1;
        for(int i = 0; i < cost.size(); i++){
            if(flag == 3){
                flag = 1;
                continue;
            }
            sum+=cost[i];
            flag++;
        }
        return sum;
    }
};