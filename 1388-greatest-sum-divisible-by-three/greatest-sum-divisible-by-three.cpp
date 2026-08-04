class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0, x1 = 30000, y1 = 30000, x2 = 30000, y2 = 30000;

        for(auto num: nums){
            sum += num;
            if(num%3 == 1){
                if(num <= x1){
                    if(num > y1)x1 = num;
                    else{
                        x1 = y1;
                        y1 = num;
                    }

                }
            }
            else if(num%3 == 2){
                if(num <= x2){
                    if(num > y2)x2 = num;
                    else{
                        x2 = y2;
                        y2 = num;
                    }

                }
            }
        }

        if(sum%3 == 0)return sum;
        else if(sum%3 == 1)return sum-min(y1,x2+y2);
        else return sum-min(y2,x1+y1);
    }
};