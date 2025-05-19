class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        j = 0
        t_len = len(t)
        for i in range(len(s)):
            while (j < t_len) and s[i] != t[j]:
                j += 1
            if (j == t_len):
                return False
            j += 1
        return True        