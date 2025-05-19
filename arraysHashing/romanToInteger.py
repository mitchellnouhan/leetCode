class Solution:
    roman_to_int = {
        'I' : 1,
        'V' : 5,
        'X' : 10,
        'L' : 50,
        'C' : 100,
        'D' : 500,
        'M' : 1000,
    }

    def romanToInt(self, s: str) -> int:
        res = 0
        s_len = len(s)
        for i in range(s_len):
            c = s[i]
            if i < s_len - 1 and self.roman_to_int[c] < self.roman_to_int[s[i + 1]]:
                res -= self.roman_to_int[c]
            else:
                res += self.roman_to_int[c]
        return res
        