class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #create a frequency based hashmap 
        freqHash = {}
        #iterate thru the array
        for num in nums:
            #if element is in hashmap, return true
            if num in freqHash:
                return True
            #if element is not in hashmap, add it
            freqHash[num] = 1
        #if you get to the end of the iteration, no duplicates!
        return False