class Solution(object):
    def isPalindrome(self, s):
        sNew = ""
        #process s:
        for char in s:
            #remove spaces, lower case the letters
            if char.isalnum():
                sNew += char.lower()
        #compare sNew with itself reversed
        #if the same, its a valid palindrome 
        return sNew == sNew[::-1]