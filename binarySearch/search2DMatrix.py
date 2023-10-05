class Solution(object):
    def binarySearchRow(self, row, target):
        l = 0
        h = len(row) - 1
        while l <= h:
            m = l + (h - l) / 2
            if target < row[m]:
                h = m - 1
            elif target > row[m]:
                l = m + 1
            else:
                return True
        return False 

    def binarySearchFirstColumn(self, matrix, target):
        #base case
        row = -1
        if target < matrix[0][0]:
            return row
        rows = len(matrix)
        l = 0
        h = rows - 1
        while l <= h:
            m = l + (h - l) / 2
            if target < matrix[m][0]:
                h = m - 1
            elif target > matrix[m][0]:
                l = m + 1
            else:
                return -2
        return h

    def searchMatrix(self, matrix, target):
        #perform a modified version of binary search on the 1st or 0th column to determine which row to look into
        row = self.binarySearchFirstColumn(matrix, target)
        #handle special function return codes
        if row == -1:
            return False    
        elif row == -2:
            return True
        #then perform a binary search on the row the previous binary search lead you to look into
        return self.binarySearchRow(matrix[row], target)