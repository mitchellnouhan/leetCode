class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        l = 0
        r = 1
        res = []
        while l < len(nums):
            start = nums[l]
            
            while r < len(nums) and nums[r] - nums[l] == 1:
                end = nums[r]
                r+=1
                l+=1
            end = nums[l]
            if start != end:
                res.append(str(start) + "->" + str(end))
            else:
                res.append(str(start))
            r += 1
            l += 1
        return res
