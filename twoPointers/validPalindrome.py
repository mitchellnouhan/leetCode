#my crack at valid palindrome
class Solution(object):
    def lowerCaseIt(self, char):
        if char >= "A" and char <= "Z":
            return chr(ord(char) + 32)
        return char

    def isAlphaNum(self, char):
        if char >= "A" and char <= "Z":
            return True
        elif char >= "a" and char <= "z":
            return True
        elif char >= "0" and char <= "9":
            return True
        return False
    
    def isPalindrome(self, s):
        left = 0
        right = len(s) - 1
        while left <= right:
            if self.isAlphaNum(s[left]) and self.isAlphaNum(s[right]):
                if self.lowerCaseIt(s[left]) != self.lowerCaseIt(s[right]):
                    return False
                left += 1
                right -= 1
            #if not, adjust left and right indexes as needed for next cycle
            elif not self.isAlphaNum(s[left]) and self.isAlphaNum(s[right]):
                left += 1
            elif self.isAlphaNum(s[left]) and not self.isAlphaNum(s[right]):
                right -= 1
            else:
                left += 1
                right -= 1
        return True