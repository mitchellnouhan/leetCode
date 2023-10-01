#my homemade attempt, got a time and space complexity efficient passing solution in 15 minutes:)
class Solution(object):
    def twoSum(self, numbers, target):
        #the big idea: assign start and end indices, figure out which index is 
        #the problem every iteration,then adjust problem index
        lowInd = 0
        highInd = len(numbers) - 1
        while (numbers[lowInd] + numbers[highInd] != target):
            if target - numbers[lowInd] > numbers[highInd]:
                #low index is the problem
                lowInd += 1
            elif target - numbers[highInd] < numbers[lowInd]:
                #high index is the problem
                highInd -= 1
        return [lowInd + 1, highInd + 1]