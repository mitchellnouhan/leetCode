class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #create an "is present" hashmap using defaultdict
        freqHash = defaultdict(lambda: False)
        #iterate thru the array
        for num in nums:
            #if element is in hashmap, return true
            if freqHash[num]:
                return True
            freqHash[num] = True
        #if you get to the end of the iteration, no duplicates!
        return False