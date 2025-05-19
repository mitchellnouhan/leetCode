class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        res = inf
        diff = inf
        for num in nums:
            cur_diff = abs(num - 0)
            if cur_diff < diff:
                diff = cur_diff
                res = num
            elif cur_diff == diff:
                res = max(res, num)
        return res
        