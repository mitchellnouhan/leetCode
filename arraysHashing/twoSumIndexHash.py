class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #create an index hash map where the (key, value) pair is
        #(<nums element value>, <list of nums elem value indeces>)
        indexHash = {}
        numLen = len(nums)
        for i in range(numLen):
            key = nums[i]
            value = i
            if key not in indexHash:
                indexHash[key] = [value]
            else:
                indexHash[key].append(value)
    
        for i in range(numLen):
            #calculate what value you need to hit target
            needed = target - nums[i]
            #check if that needed value exists in indexHash
            if needed in indexHash:
                if nums[i] == needed:
                    if len(indexHash[needed]) > 1:
                        return [indexHash[needed][0], indexHash[needed][1]]
                else:
                    return [i, indexHash[needed][0]]