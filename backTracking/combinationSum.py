class Solution:
    def __init__(self):
        self.target = 0
        self.res =[]

    def dfsbt(self, i: int, curSum: int, curSumList: List[int], nums: List[int]):
        if curSum == self.target:
            self.res.append(curSumList)
            return
        elif curSum > self.target:
            return
        
        for j in range(i, len(nums)):
            self.dfsbt(j, curSum + nums[j], curSumList + [nums[j]], nums)

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        self.target = target
        self.dfsbt(0, 0, [], nums)
        return self.res   