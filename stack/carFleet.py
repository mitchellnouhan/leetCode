#Monotonic decreasing stack where elements being stacked are calculated times for group to reach target
class Solution(object):
    def carFleet(self, target, position, speed):

        groups = []
        timeToTarget = [0] * len(position)
        for i in range(len(position)):
            timeToTarget[i] = float((target - position[i])) / speed[i]

        posSortedTimeToTarget = sorted(zip(position,timeToTarget), key = lambda x: x[0])
        for carTime in posSortedTimeToTarget:
            while len(groups) and groups[-1] <= carTime[1]:
                groups.pop(-1)
            groups.append(carTime[1])

        return len(groups)