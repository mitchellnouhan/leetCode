class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rowNum, colNum = 9, 9
        subBoxNum = 3
        rows = [[False for i in range(rowNum)] for j in range(rowNum)]
        cols = [[False for i in range(colNum)] for j in range(colNum)]
        subBoxes = [[[False for i in range(rowNum)] for j in range(subBoxNum)] for k in range(subBoxNum)]
        for row in range(len(board)):
            for col in range(len(board[row])):
                elem = board[row][col]
                if elem != ".":
                    elem = int(elem) - 1
                    subRow = row // 3
                    subCol = col // 3
                    if rows[row][elem] or cols[col][elem] or subBoxes[subRow][subCol][elem]:
                        return False
                    rows[row][elem] = True
                    cols[col][elem] = True
                    subBoxes[subRow][subCol][elem] = True
        return True