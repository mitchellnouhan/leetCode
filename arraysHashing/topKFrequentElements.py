class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        #use a frequency based hash map
        #create an hashmap:
        freqHash = defaultdict(lambda: 0)
        for num in nums:
            #(key,val) = (unique num in nums, frequency it appears in nums)
            freqHash[num] += 1
        #sort hash map based on its freq values
        freqHash = sorted(freqHash.items(),key=lambda x: x[1],reverse=True)
        kFreqElements = []
        for i in range(k):
            item = freqHash[i][0]
            kFreqElements.append(item)
        #return the first/last k indexes of sorted hashmap
        return kFreqElements