class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            cur_len = 1
            cur_num = num
            while cur_num + 1 in nums:
                cur_num += 1
                cur_len += 1
            res = max(res, cur_len)
        return res