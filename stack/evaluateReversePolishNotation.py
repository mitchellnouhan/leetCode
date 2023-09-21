class Solution(object):
    def Operation(self, operand1, operand2, operator):
        if operator == '+':
            return operand1 + operand2
        elif operator == '-':
            return operand1 - operand2
        elif operator == '*':
            return operand1 * operand2
        else:
            operand1 = float(operand1)
            operand2 = float(operand2)
            if operand1 / operand2 < 0:
                return math.ceil(operand1 / operand2)
            return math.floor(operand1 / operand2)
    def isOperator(self, token):
        if token == '+' or token == '-' or token == '*' or token == '/':
            return True
        return False
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        #iterate thru tokens
        for token in tokens:
            #if token is operator
            if self.isOperator(token):
                #pop 2 operands off
                operand2 = int(stack.pop(-1))
                operand1 = int(stack.pop(-1))
                #evalute expression, then push result back onto the stack
                new = self.Operation(operand1,operand2,token) 
                stack.append(new)
            else:
                #push operands onto the stack
                stack.append(token)
        #if done properly, after iterating thru all tokens, a single value  should remain on the stack
        return int(stack[0])