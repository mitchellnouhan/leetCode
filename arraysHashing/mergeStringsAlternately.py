class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res = ""
        word1_len = len(word1)
        word2_len = len(word2)
        for i in range(min(word1_len, word2_len)):
            res += (word1[i] + word2[i])
        
        if(word1_len < word2_len):
            res += word2[word1_len:]
        elif(word2_len < word1_len):
            res += word1[word2_len:]
        
        return res