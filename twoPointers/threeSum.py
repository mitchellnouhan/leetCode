class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums = sorted(nums)
        for s in range(len(nums) - 2):
            if s and nums[s] == nums[s - 1]:
                continue
            l, r = s + 1, len(nums) - 1
            while l < r:
                threeSum = nums[s] + nums[l] + nums[r]
                if threeSum < 0:
                    l += 1
                elif threeSum > 0:
                    r -= 1
                else:
                    res.append([nums[s], nums[l], nums[r]])
                    l += 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
        return res