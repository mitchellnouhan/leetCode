class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        group_anagrams = defaultdict(list)
        for string in strs:
            letter_freq = [0 for _ in range(26)]
            for c in string:
                letter_freq[ord(c) - ord('a')] += 1
            group_anagrams[tuple(letter_freq)].append(string)
        return list(group_anagrams.values())