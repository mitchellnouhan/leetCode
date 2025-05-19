class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        b = 0
        s = 0
        while s < len(prices):
            profit = prices[s] - prices[b]
            if profit < 0:
                b = s
            else:
                res = max(res, profit)
            s += 1
        return res