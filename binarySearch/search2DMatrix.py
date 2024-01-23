class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l, r = 0, len(matrix) - 1
        while l <= r:
            m = l + (r - l // 2)
            if target < matrix[m][0]:
                r = m - 1
            elif target > matrix[m][0]:
                l = m + 1
            else:
                return True
        row = max(min(l, r), 0)
        l, r = 0, len(matrix[row]) - 1
        while l <= r:
            m = l + (r - l // 2)
            if target < matrix[row][m]:
                r = m - 1
            elif target > matrix[row][m]:
                l = m + 1
            else:
                return True
        return False