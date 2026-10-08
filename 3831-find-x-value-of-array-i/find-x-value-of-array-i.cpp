class Solution {
public:
/*
    We need to remove a prefix and a suffix, so the part that remains
    is simply a contiguous subarray.

    Therefore, the problem reduces to:
        Count all subarrays whose product % k == r
        for every remainder r from 0 to k-1.

    Brute force would consider O(N^2) subarrays, which is too expensive.

    ---------------------------------------------------------------
    DP / STATE
    ---------------------------------------------------------------

    Let's process the array from left to right.
    For every index i, consider ALL subarrays that end at i:

        [i, i]
        [i-1, i]
        [i-2, i]
        ...
        [0, i]

    Instead of storing these subarrays individually, we only care about
    their product modulo k.

    So:

        prev[r] = number of subarrays ending at index i-1
                  whose product % k == r

    Now we want to calculate the corresponding information for index i.

    ---------------------------------------------------------------
    TRANSITION
    ---------------------------------------------------------------

    There is one new subarray consisting of only nums[i]:

        [i, i]

    Its product modulo k is:

        nums[i] % k

    Hence:

        curr[nums[i] % k] += 1

    Every previous subarray ending at i-1 can be extended by nums[i].
    Suppose a previous subarray has:
        product % k = r
    After adding nums[i], its new product modulo k becomes:
        (r * nums[i]) % k

    Therefore:
        curr[(r * nums[i]) % k] += prev[r]
    This accounts for every subarray ending at i exactly once.

    ---------------------------------------------------------------
    WHY DO WE ONLY STORE k STATES?
    ---------------------------------------------------------------

    We don't need to know the actual product.
    We only care about product % k.
    There are only k possible remainders:
        0, 1, 2, ..., k-1
    So instead of maintaining O(N) different products for every index,
    we maintain only k counts.

    ---------------------------------------------------------------
    FINAL ANSWER
    ---------------------------------------------------------------

    After computing curr for index i, curr[r] tells us:

        number of subarrays ending at i
        whose product % k == r

    These are valid subarrays, so we add them to the global answer:
        res[r] += curr[r]

    After processing all indices, res[r] is the total number of
    subarrays whose product % k == r.
*/
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prev(k,0), res(k,0);

        for(int i = 0; i < n; i++){
            vector<long long> curr(k,0);
            curr[nums[i]%k] = 1LL;

            for(int j = 0; j < k; j++){
                curr[(1LL*j*nums[i])%k] += prev[j];
            }
            prev = curr;

            for(int j = 0; j < k; j++)res[j] += prev[j];
        }

        return res;

    }
};