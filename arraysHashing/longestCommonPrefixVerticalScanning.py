class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        
        res = ""
        i = 0
        min_len = inf
        for string in strs:
            min_len = min(min_len, len(string))
        
        for i in range(min_len):
            cur_char = strs[0][i]
            for string in strs:
                if string[i] != cur_char:
                    return res
            res += cur_char
        return res