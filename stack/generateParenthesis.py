class Solution:
    def __init__(self):
        self.res = []

    def addParentheses(self, o: int, c: int, s: str):
        if not o and not c:
            self.res.append(s)
            return 
        elif o == c:
            self.addParentheses(o - 1, c, s + "(")
        elif not o and c:
            self.addParentheses(o, c - 1, s + ")")
        else:
            self.addParentheses(o - 1, c, s + "(")
            self.addParentheses(o, c - 1, s + ")")

    def generateParenthesis(self, n: int) -> List[str]:
        self.addParentheses(n, n, "")
        return self.res  