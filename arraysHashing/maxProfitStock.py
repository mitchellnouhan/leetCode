class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP, b, s = 0, 0, len(prices) - 1
        buyMin, sellMax = [prices[b]] * len(prices), [prices[s]] * len(prices)
        for i in range(1, len(prices)):
            buyMin[b + i] = min(buyMin[b + i - 1], prices[b + i])
            sellMax[s - i] = max(sellMax[s - i + 1], prices[s - i])
        for i in range(len(prices)):
            maxP = max(maxP, sellMax[i] - buyMin[i])
        return maxP