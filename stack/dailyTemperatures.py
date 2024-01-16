class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0] * len(temperatures)
        for i, temp in enumerate(temperatures):
            while len(stack) and temp > stack[-1][0]:
                update = stack.pop()
                res[update[1]] = i - update[1]
            stack.append([temp, i])
        return res