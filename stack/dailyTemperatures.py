#Implement using a monotonic decreasing stack
#what got me was that updating the stack will assign answer values to a different index than the temperature you're currently at in the temperatures array
#an optimization is that you don't need to have (temp, index) lists on the stack, only indexes! bc you can always grab the temp value from the original temperatures list! saves time and memory!!
class Solution(object):
    def dailyTemperatures(self, temperatures):
        #init an answer list of 0's
        tempLen = len(temperatures)
        answer = [0] * tempLen
        stack = []
        for i in range(tempLen):
            #if temp value is greater than top of stack pop & update answer arr
            while stack and temperatures[i] > temperatures[stack[-1]]:
                answer[stack[-1]] = i - stack[-1]
                stack.pop(-1)
            #push index pair onto stack after popping stack
            stack.append(i)
        return answer