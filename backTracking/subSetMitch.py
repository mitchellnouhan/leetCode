class Solution:
    def __init__(self):
        self.res = []

    def backtrack(self, cur: List[int], nums: List[int]):
        if len(nums) == 0:
            self.res.append(cur)
            return
        self.backtrack(cur, nums[1:])
        self.backtrack(cur + [nums[0]], nums[1:])
        return

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.backtrack([], nums)
        return self.res