class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        #Create a frequency hash map of t
        tFreqHash = {}
        for tChar in t:
            if tChar not in tFreqHash:
                tFreqHash[tChar] = 1
            else:
                tFreqHash[tChar] += 1
        #iterate thru s and modify freqDict of t
        for sChar in s:
            if sChar not in tFreqHash:
                return False
            tFreqHash[sChar] -= 1
        #if freqDict of t isn't all zeros, return false
        for key in tFreqHash:
            if tFreqHash[key] != 0:
                return False
        return True