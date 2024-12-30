class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def dfsbt(i: int, nums: List[int], curList: List[int]):
            if i == len(nums):
                if not res[tuple(curList)]:
                    res[tuple(curList)] = True
                return 
            dfsbt(i + 1, nums, curList + [nums[i]])
            dfsbt(i + 1, nums, curList)
            return

        nums = sorted(nums)
        res = defaultdict(lambda: False)
        dfsbt(0, nums, [])
        resFinal = [list(subset) for subset in res.keys()]
        return resFinal        