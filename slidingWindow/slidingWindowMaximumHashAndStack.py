#my crack at solving this problem with a montonic decreasing stack and hashMap
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        slidingWindowMax = []
        stack = []
        indHash = defaultdict(lambda: -1)

        l, r = 0, 0
        for r in range(k):
            while len(stack) and nums[r] >= stack[-1]:
                del indHash[stack.pop()]

            indHash[nums[r]] = r
            stack.append(nums[r])
        slidingWindowMax.append(stack[0])
        
        for r in range(r + 1, len(nums)):
            #del l from stack
            if indHash[nums[l]] == l:
                stack.remove(nums[l])
                del indHash[nums[l]]

            l += 1

            while len(stack) and nums[r] >= stack[-1]:
                del indHash[stack.pop()]
            
            indHash[nums[r]] = r
            stack.append(nums[r])
            slidingWindowMax.append(stack[0])
        
        return slidingWindowMax