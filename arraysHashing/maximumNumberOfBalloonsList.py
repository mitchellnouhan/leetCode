class Solution:
    balloon = "balloon"

    def extract_balloon(self, letter_freq: List[int]) -> bool:
        for c in self.balloon:
            if letter_freq[ord(c) - ord('a')] == 0:
                return False
            letter_freq[ord(c) - ord('a')] -= 1
        return True

    def maxNumberOfBalloons(self, text: str) -> int:
        res = 0

        letter_freq = [0 for _ in range(26)]

        for c in text:
            letter_freq[ord(c) - ord('a')] += 1
        
        while self.extract_balloon(letter_freq):
            res += 1
        
        return res