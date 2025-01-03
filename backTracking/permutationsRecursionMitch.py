class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [nums]
        
        resultFinal = []
        for i in range(len(nums)):
            for res in self.permute(nums[:i] + nums[i+1:]):
                resultFinal.append([nums[i]] + res)
        return resultFinal