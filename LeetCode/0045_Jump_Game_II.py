class Solution:
    def jump(self, nums):
        if len(nums) == 1:
            return 0
        jump = 0
        cur = 0
        next = 0
        for i in range(len(nums)):
            if i > cur:
                jump += 1
                if cur == next:
                    return -1
                cur = next
            next = max(next, nums[i] + i)
        return jump
