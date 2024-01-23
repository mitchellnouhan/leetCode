class Solution(object):
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP, b, s = 0, 0, 0
        while s < len(prices):
            if prices[b] >= prices[s]:
                b = s
            else:
                maxP = max(maxP, prices[s] - prices[b])
            s += 1
        return maxP