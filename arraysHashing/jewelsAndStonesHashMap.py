class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        res = 0
        jewels_present = defaultdict(lambda: False)
        for jewel in jewels:
            jewels_present[jewel] = True
        for stone in stones:
            if jewels_present[stone]:
                res += 1
        return res
        