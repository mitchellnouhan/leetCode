class Solution:
    def trap(self, height: List[int]) -> int:
        water = 0
        l, r = 0, 0
        while r < len(height) and not height[r]:
            l, r = l + 1, r + 1
        while r < len(height):
            rearMax = height[l]
            r += 1
            while r < len(height) and height[r] < rearMax:
                r += 1
            while r < len(height) and l < r:
                water += max(rearMax - height[l], 0) 
                l += 1
        r -= 1
        rearMax = 0
        while l < r:
            rearMax = max(rearMax, height[r])
            water += max(rearMax - height[r], 0)
            r -= 1
        return water