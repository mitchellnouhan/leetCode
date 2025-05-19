class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        # check each bit of all nums
        # if that bit is present for the majority of the elements, add to res
        for i in range(32):
            bit = 1 << i
            bit_count = 0
            for num in nums:
                if bit & num:
                    bit_count += 1
            if bit_count > (n // 2):
                res += bit
        bit = 1 << 31
        neg_nums = 0
        for num in nums:
            if num < 0:
                neg_nums += 1
        if neg_nums > (n // 2):
            res -= (2 * bit)
        return res