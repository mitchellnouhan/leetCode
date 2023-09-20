class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # had to peek at NeetCode to see that, you optimal solution uses an index hash map, however, it can be done in one pass!
        indexHash = {}
        numLen = len(nums)
        for i in range(numLen):
            key = nums[i]
            value = i
            needed = target - nums[i]
            #check if needed value is in hash map first, then add key to hash map, this way we don't have the funky edge case if statements to handle needed == nums[i] case (clever)

            if needed in indexHash:
                return [i, indexHash[needed][0]]
            
            if key in indexHash:
                indexHash[key].append(value)
            else:
                indexHash[key] = [value]
