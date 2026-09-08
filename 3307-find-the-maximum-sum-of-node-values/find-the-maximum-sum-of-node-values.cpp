class Solution {
public:
    /*
    if we want to xor two nodes u and v which are not adjacent , can we do that??
    we can, 
        let's say u - n1 - n2 - n3 ... - v
        we know the property of xor that a^a = 0
        so lets start with u - n1 edges , new value will be u^k, n1^k
        then n1 - n2 edges, new value be n1^k^k = n1, n2^k
        and so on till last edge - v where we will have v^k

        so if we can xor all the nodes to its max value

        it should be noted that we need to nodes to xor with k 
        what if we have odd no of nodes which can be increased when doing xor with k
        then in that case we have to pick one node which have minium loss to its value when doing xor with k
        therefor we have to keep track of how many nodes can be increased and if a nodes gets decreased then what is the minm loss i can handle

    to maximize the answer we can increase the nums[i] to its xor value with k if it is more than nums[i] and increase the counts of xor values, and keep a track of minLoss when our node value decreases

    */
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long maxSum = 0, cntXor = 0, minLoss = LLONG_MAX;
        for(int i = 0; i < nums.size(); i++){
            // cout<<(nums[i]^k)<<" ";
            if((nums[i]^k) >= nums[i]){
                cntXor++;
                maxSum += (nums[i]^k);
            }
            else{
                maxSum += nums[i];
            }

            minLoss = min(minLoss,1LL*abs(nums[i] - (nums[i]^k)));
        }
        // cout<<endl<<cntXor<<" "<<minLoss<<endl;
        if(cntXor % 2 == 0)return maxSum;
        else return maxSum - minLoss;
    }
};