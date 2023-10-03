class Solution(object):
    def threeSum(self, nums):
        triplets = []
        nums.sort()
        numsLen = len(nums)
        for i, num in enumerate(nums):
            if i and num == nums[i - 1]:
                continue
            low = i + 1
            high = numsLen - 1
            while low < high:
                if num + nums[low] + nums[high] > 0:
                    high -= 1
                elif num + nums[low] + nums[high] < 0:
                    low += 1
                else:
                    triplets.append([num, nums[low], nums[high]])
                    high -= 1
                    low += 1
                    while low < high and nums[high] == nums[high + 1]:
                        high -= 1
                    while low < high and nums[low] == nums[low - 1]:
                        low -= 1
        return triplets