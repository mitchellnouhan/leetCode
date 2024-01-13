class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == "*" or token == "/" or token == "+" or token == "-":
                operandc, operandb, operanda = 0, stack.pop(), stack.pop()
                if token == "*":
                    operandc = operanda * operandb
                elif token == "/":
                    operandc = operanda // operandb
                    operandc = (operandc + 1) if ((operandc < 0) and (operanda % operandb) != 0) else operandc
                elif token == "+":
                    operandc = operanda + operandb
                else:
                    operandc = operanda - operandb
                stack.append(operandc) 
            else:
                stack.append(int(token))
        return stack.pop()  