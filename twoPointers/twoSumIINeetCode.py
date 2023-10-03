class Solution(object):
    def twoSum(self, numbers, target):
        low = 0
        high = len(numbers) - 1
        while low < high:
            if numbers[low] + numbers[high] > target:
                high -= 1
            elif numbers[low] + numbers[high] < target:
                low += 1
            else:
                return [low + 1, high + 1]