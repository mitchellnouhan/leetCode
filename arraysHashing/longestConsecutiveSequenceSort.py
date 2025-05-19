class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        nums.sort()
        if len(nums) == 0:
            return res
        res = 1
        cur = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                if nums[i] == nums[i - 1] + 1:
                    cur += 1
                else:
                    res = max(res, cur)
                    cur = 1      
        return max(res, cur)