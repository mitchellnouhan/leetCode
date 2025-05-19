class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        res = []
        n = len(nums)
        l = 0
        r = n - 1
        while l <= r:
            if abs(nums[l]) < abs(nums[r]):
                res.append(int(nums[r] ** 2))
                r -= 1
            else:
                res.append(int(nums[l] ** 2))
                l += 1
        return res[::-1]