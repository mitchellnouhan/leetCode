class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        while l < r:
            m = l + (r - l) // 2
            time = 0
            for pile in piles:
                time += math.ceil(pile / m)
            if time > h:
                l = m + 1
            else:
                r = m 
        return r  