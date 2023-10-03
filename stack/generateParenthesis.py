#use n, openCount, and closeCount to generate the valid paren combos with recursion 
class Solution(object):
    def __init__(self):
        self.paren = []
        self.openCount = 0
        self.closeCount = 0
        self.curString = ""

    def helper(self, openCount, closeCount, curString, n):
        if closeCount < openCount:
            self.helper(openCount, closeCount + 1, curString + ')', n)
        if openCount < n:
            self.helper(openCount + 1, closeCount, curString + '(', n)
        if openCount == n and closeCount == n:
            self.paren.append(curString)

    def generateParenthesis(self, n):
        self.helper(self.openCount, self.closeCount, self.curString, n)
        return self.paren     