class Solution(object):
    def checkInclusion(self, s1, s2):
        numberOfLetters = 26
        s1CharArr = [0] * numberOfLetters
        s1Sum = 0
        for letter in s1:
            s1CharArr[ord(letter) - ord("a")] += 1
            s1Sum += 1
        
        l, r = 0, 0
        s2Len = len(s2)
        while r < s2Len:
            while r < s2Len and not s1CharArr[ord(s2[r]) - ord("a")]:
                r += 1
                l += 1
            if r >= s2Len:
                return False
            
            while r < s2Len and s1CharArr[ord(s2[r]) - ord("a")]:
                s1CharArr[ord(s2[r]) - ord("a")] -= 1
                s1Sum -= 1
                r += 1
            if s1Sum == 0:
                return True
            elif r >= s2Len:
                return False
            
            while l < r and not s1CharArr[ord(s2[r]) - ord("a")]:
                s1CharArr[ord(s2[l]) - ord("a")] += 1
                s1Sum += 1
                l += 1 