class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        letter_freq = [0 for _ in range(26)]
        for c in magazine:
            letter_freq[ord(c) - ord('a')] += 1
        for c in ransomNote:
            letter_freq[ord(c) - ord('a')] -= 1
            if letter_freq[ord(c) - ord('a')] < 0:
                return False
        return True
