class Solution(object):
    def timeItTakesToEat(self, piles, speed):
        time = 0
        for pile in piles:
            time += ceil(float(pile)/speed)
        return int(time)

    def minEatingSpeed(self, piles, h):
        l = 1
        r = max(piles)
        while l <= r:
            m = l + (r - l) / 2
            #we ate too fast 
            if h - self.timeItTakesToEat(piles, m) >= 0:
                r = m - 1
            #we ate too slow
            else:
                l = m + 1
        return l