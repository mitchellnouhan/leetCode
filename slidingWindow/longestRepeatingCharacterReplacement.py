class Solution(object):
    def characterReplacement(self, s, k):
        numberOfLetters = 26
        charArr = [0] * numberOfLetters
        l, r = 0, 0
        maxLen = 0
        sLen = len(s)
        while r <= sLen:
            if (r - l) - max(charArr) > k:
                charArr[ord(s[l]) - ord("A")] -= 1
                l += 1
            else:
                maxLen = max(maxLen, r - l)
                if r < sLen:
                    charArr[ord(s[r]) - ord("A")] += 1
                r += 1         
        return maxLen