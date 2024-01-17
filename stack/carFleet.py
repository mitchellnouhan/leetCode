class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        stack = []
        for i in range(len(speed)):
            speed[i] = (target - position[i]) / (speed[i])
        times = [time for _, time in sorted(zip(position, speed))]
        for time in times:
            while len(stack) and time >= stack[-1]:
                stack.pop()
            stack.append(time)
        return len(stack)