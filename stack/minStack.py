#Implemented a min stack after reading leetcode's hint, using a list of (val, curren running Min pair) elements
#taking advantage of python's built in append & pop functions along with the -1 index feature
class MinStack(object):

    def __init__(self):
        self.stack = []

    def push(self, val):
        if len(self.stack) == 0 or val < self.getMin():
            self.stack.append((val, val))
        else:
            self.stack.append((val, self.getMin()))

    def pop(self):
        self.stack.pop(-1)

    def top(self):
        return self.stack[-1][0]   

    def getMin(self):
        return self.stack[-1][1]