class Solution(object):
    def characterReplacement(self, s, k):
        numberOfLetters = 26
        charArr = [0] * numberOfLetters
        l = 0
        maxLen = 0
        for r in range(len(s)):
            charArr[ord(s[r]) - ord("A")] += 1
            while (r - l + 1) - max(charArr) > k:
                charArr[ord(s[l]) - ord("A")] -= 1
                l += 1
            maxLen = max(maxLen, (r - l + 1))
        return maxLen