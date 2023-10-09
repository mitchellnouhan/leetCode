class Solution(object):
    def maxProfit(self, prices):
        maxProfit = 0
        priceLen = len(prices)
        buy, sell = 0, 1
        while sell < priceLen:
            curProfit = prices[sell] - prices[buy]
            maxProfit = max(maxProfit, curProfit)
            if curProfit <= 0:
                buy = sell
            sell += 1
        return maxProfit