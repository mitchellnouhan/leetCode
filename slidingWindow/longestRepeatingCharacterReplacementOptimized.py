class Solution(object):
    def characterReplacement(self, s, k):
        numberOfLetters = 26
        charArr = [0] * numberOfLetters
        maxF, l = 0, 0
        maxLen = 0
        for r in range(len(s)):
            charArr[ord(s[r]) - ord("A")] += 1
            maxF = max(maxF, charArr[ord(s[r]) - ord("A")])
            while (r - l + 1) - maxF > k:
                charArr[ord(s[l]) - ord("A")] -= 1
                l += 1
            maxLen = max(maxLen, (r - l + 1))
        return maxLen