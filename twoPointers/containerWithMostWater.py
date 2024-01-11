class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxWater, l, r = 0, 0, len(height) - 1
        while l < r:
            maxWater = max(maxWater, (r - l) * min(height[l], height[r]))
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return maxWater