class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        j_set = set(jewels)
        return len([s for s in stones if s in j_set])