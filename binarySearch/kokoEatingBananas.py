#my first go at the Koko Eating Bananas problem

class Solution(object):
    def timeItTakesToEat(self, piles, speed):
        time = 0
        for pile in piles:
            time += ceil(float(pile)/speed)
        return int(time)

    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        #course tune w/ binary pick
        piles.sort()
        fineTune = 0
        pilesLen = len(piles)
        l = 1
        r = piles[pilesLen - 1]
        while fineTune == 0 and l <= r:
            m = l + (r - l) / 2
            simulationResult = h - self.timeItTakesToEat(piles, m)
            #we ate too fast
            if simulationResult > 0:
                r = m - 1
            #we ate too slow
            elif simulationResult < 0:
                l = m + 1
            else:
                fineTune = m
        
        #fine tune
        if l > r:
            return l
        
        while fineTune - 1 and h - self.timeItTakesToEat(piles, fineTune - 1) == 0:
            fineTune -= 1
        
        return fineTune