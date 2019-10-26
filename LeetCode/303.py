#Problem: 303. Range Sum Query - Immutable
#https://leetcode.com/problems/range-sum-query-immutable/
#Author: Luis Herrera
#Summary: We use a prefix array to make the queries in constant time O(1).

class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.prefix_sum = [0] * len(nums)
        if len(nums) > 0:
            self.prefix_sum[0] = nums[0]
            for i in range(1, len(nums)):
                self.prefix_sum[i] = self.prefix_sum[i - 1] + nums[i]
        

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if i > 0 :
            return self.prefix_sum[j] - self.prefix_sum[i - 1]
        return self.prefix_sum[j]
