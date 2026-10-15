class Solution(object):
    def sumCounts(self, nums):
        res = 0
        n = len(nums)
        for i in range(0,n):
            s = set()
            for j in range(i,n):
                s.add(nums[j])
                ln = len(s)
                res += ln*ln
        
        return res
        