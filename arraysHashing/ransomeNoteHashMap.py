class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        letter_freq = defaultdict(lambda: 0)
        for c in magazine:
            letter_freq[c] += 1
        for c in ransomNote:
            letter_freq[c] -= 1
            if letter_freq[c] < 0:
                return False
        return True