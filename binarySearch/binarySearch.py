class Solution(object):
    def search(self, nums, target):
        l = 0
        h = len(nums) - 1
        while l <= h:
            m = l + (h - l) / 2
            if target > nums[m]:
                l = m + 1
            elif target < nums[m]:
                h = m - 1
            else:
                return m
        return -1