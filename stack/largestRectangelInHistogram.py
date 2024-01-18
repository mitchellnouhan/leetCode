class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        maxRect = 0
        for i, h in enumerate(heights):
            backBound = i
            while stack and h < stack[-1][1]:
                index, height = stack.pop()
                maxRect = max(maxRect, height * (i - index))
                backBound = index
            stack.append([backBound, h])
        for index, height in stack:
            maxRect = max(maxRect, height * (len(heights) - index))
        return maxRect