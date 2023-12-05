class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(lambda: 0)
        for num in nums:
            freq[num] += 1
        freq = dict(sorted(freq.items(), key = lambda x: x[1], reverse=True))
        return list(freq.keys())[0:k]