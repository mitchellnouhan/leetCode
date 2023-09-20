class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        numsLen = len(nums)
        for i in range(numsLen):
            for j in range(i + 1, numsLen):
                if nums[i] + nums[j] == target:
                    return [i, j]