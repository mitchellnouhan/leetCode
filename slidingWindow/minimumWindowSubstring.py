class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        #create need dictionary
        #create have dictionary based on need
        need, have = {}, {}
        needSum, haveSum = 0, 0

        for letter in t:
            if letter in need:
                need[letter] += 1
            else:
                need[letter] = 1
                needSum += 1
                have[letter] = 0

        
        l, r = 0, 0
        minWinSub = ""
        sLen = len(s)
        while r <= sLen:
            #while l<=r, iterate l,r until s[l] is on something we need
            while r <= sLen and l < sLen and s[l] not in need:
                if l == r:
                    r += 1    
                l += 1
            if r > sLen or l >= sLen:
                break
               
            #increment r until we have what we need
            while r <= sLen and haveSum < needSum:
                if r == sLen:
                    return minWinSub

                if s[r] in have:
                    have[s[r]] += 1
                    if have[s[r]] == need[s[r]]:
                        haveSum += 1
                r += 1
            if r > sLen:
                break

            #while we have everthing we need, update min win substring, increment l
            while haveSum == needSum:
                if len(s[l:r]) < len(minWinSub) or minWinSub == "":
                    minWinSub = s[l:r]

                if s[l] in have:
                    have[s[l]] -= 1
                    if have[s[l]] < need[s[l]]:
                        haveSum -= 1
                l += 1

        return minWinSub