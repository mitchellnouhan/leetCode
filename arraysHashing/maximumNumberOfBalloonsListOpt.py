class Solution:
    balloon = "balloon"

    def maxNumberOfBalloons(self, text: str) -> int:
        res = inf

        letter_freq = [0 for _ in range(26)]
        balloon_freq = [0 for _ in range(26)]

        for c in text:
            letter_freq[ord(c) - ord('a')] += 1
        
        for c in self.balloon:
            balloon_freq[ord(c) - ord('a')] += 1
        
        for i in range(26):
            if balloon_freq[i]:
                letter_pot = letter_freq[i] // balloon_freq[i]
                res = min(res, letter_pot)
        return res