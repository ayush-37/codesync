class Solution {
public:
    /*
    Let prev be the previous element and curr be the current element. Initially, prev = 0.

    Case 1: curr > prev

    The current element is greater than the previous element, so we need at least curr - prev additional operations to increase its value from prev to curr.

    We can achieve this by performing operations on subarrays that include index i. Hence, we add curr - prev to the answer.

    Case 2: curr <= prev

    We don't need any additional operations at the current index because the previous element is already greater than or equal to curr. The operations required to build the previous height have already contributed to the answer, and we can reuse those operations to construct the current element without any extra cost.

    Therefore, we only add the positive increase between consecutive elements:

    ans += max(0, curr - prev)

    Finally, update prev = curr and continue traversing the array.

    Conclusion: The minimum number of operations is the sum of all positive differences between consecutive elements, treating the initial previous value as 0.
        
    */
    int minNumberOperations(vector<int>& target) {
        int ans = 0, prev = 0;
        for(auto curr: target){
            if(curr > prev)ans += curr - prev;
            prev = curr;
        }

        return ans;
    }
};