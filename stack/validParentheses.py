class Solution(object):
    def isCorrectPair(self, open, close):
        if open == '(':
            return close == ')'
        elif open == '{':
            return close == '}'
        elif open == '[':
            return close == ']'
        return False
    def isOpen(self, paren):
        if paren == '(' or paren == '{' or paren == '[':
            return True
        return False
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        #create stack
        stack = []
        for paren in s:
            #come across a open parentheses, push onto the stack
            if self.isOpen(paren):
                stack.append(paren)
            #come across a closed parenthese, pop off the stack and compare
            else:
                if len(stack) == 0:
                    return False
                if not self.isCorrectPair(stack.pop(-1), paren):
                    return False
        if len(stack) == 0:
            return True
        return False