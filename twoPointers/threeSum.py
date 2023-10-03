#my crack at it
class Solution(object):
    def __init__(self):
        self.target = 0
    
    def twoSum(self, target, nums):
        triplets = []
        lowInd = 0
        highInd = len(nums) - 1
        while lowInd < highInd:
            if nums[lowInd] + nums[highInd] == target:
                triplets.append([-1*target, nums[lowInd], nums[highInd]])
                lowInd += 1
                highInd -= 1
            
            lowNeeded = target - nums[lowInd]
            highNeeded = target - nums[highInd]
            if lowNeeded > nums[highInd] and highNeeded < nums[lowInd]:
                break
            
            if lowNeeded > nums[highInd]:
                lowInd += 1
            elif highNeeded < nums[lowInd]:
                highInd -= 1
        return triplets

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        #sort nums
        #iterate thru each elem, and apply the twoSum II approach to the element at hand with the rest of the nums array to the right of the elem
        triplets = set()
        nums = sorted(nums)
        for i,num in enumerate(nums):
            for trip in self.twoSum(self.target - num, nums[i + 1:]):
                triplets.add(tuple(trip))
        return list(triplets)