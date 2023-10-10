class Solution(object):
    def lengthOfLongestSubstring(self, s):
        numberOfAscii = 128
        indArr = [0] * numberOfAscii
        l, r = 0, 0
        maxSubStringLen = 0
        strLen = len(s)
        while r < strLen:
            if indArr[ord(s[r])]:
                indArr[ord(s[l])] -= 1
                l += 1
            else:
                indArr[ord(s[r])] += 1
                r += 1
                maxSubStringLen = max(maxSubStringLen, r - l)
        return maxSubStringLen