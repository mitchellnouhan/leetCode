#Peaked at neetcode's solution using prefix and postfix running product but there is a more optimal way to implement this solution!
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        numsLen = len(nums)
        preFix = [1] * numsLen
        postFix = [1] * numsLen
        #pass through and create prefix running sum
        for i in range(numsLen):
            if i == 0:
                preFix[i] = nums[i]
            else:
                preFix[i] = nums[i] * preFix[i - 1]
        #pass through and create postfix running sum
        for i in range(numsLen - 1,-1,-1):
            if i == numsLen - 1:
                postFix[i] = nums[i]
            else:
                postFix[i] = nums[i] * postFix[i + 1]
        #iterate through nums, assign each element to prefix * postfix sums
        for i in range(numsLen):
            if i == 0:
                nums[i] = postFix[i + 1]
            elif i == numsLen - 1:
                nums[i] = preFix[i - 1]
            else:
                nums[i] = preFix[i - 1] * postFix[i + 1]
        return nums