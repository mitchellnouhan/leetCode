class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if ch == "(" or ch == "[" or ch =="{":
                stack.append(ch)
            elif not len(stack):
                return False
            elif (ch == ")" and stack.pop() != "(") or (ch == "]" and stack.pop() != "[") or (ch == "}" and stack.pop() != "{"):
                return False
        return False if len(stack) else True