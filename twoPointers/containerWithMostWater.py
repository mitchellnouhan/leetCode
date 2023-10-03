class Solution(object):
    def maxArea(self, height):
        maxArea = 0
        low = 0
        high = len(height) - 1
        while low < high:
            maxArea = max(maxArea, min(height[high], height[low]) * (high - low))
            if height[high] < height[low]:
                high -= 1
            else:
                low += 1
        return maxArea