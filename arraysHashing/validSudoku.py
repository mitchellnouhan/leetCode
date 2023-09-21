class Solution(object):
    def myInit(self):
        self.rowMaps = [[False for _ in range(9)] for _ in range(9)]
        self.colMaps = [[False for _ in range(9)] for _ in range(9)]
        self.squareMaps = [[[False for _ in range(9)] for _ in range(3)] for _ in range(3)]     

    def isNumber(self, elem): 
        if elem >= "0" and elem <= "9":
            return True
        return False

    def processRow(self, row, elem):
        if self.rowMaps[row][elem]:
            return True
        
        self.rowMaps[row][elem] = True
        return False

    def processCol(self, col, elem):
        if self.colMaps[col][elem]:
            return True
        self.colMaps[col][elem] = True
        return False

    def processSquare(self, square, elem):
        if self.squareMaps[square[0]][square[1]][elem]:
            return True
        self.squareMaps[square[0]][square[1]][elem] = True
        return False

    def processElem(self, row, col, square, elem):
        if self.isNumber(elem):
            elem = ord(elem) - ord("0") - 1
            return self.processRow(row, elem) or self.processCol(col, elem) or self.processSquare(square, elem)
        return False

    def isValidSudoku(self, board):
        self.myInit()
        for i in range(len(board)):
            for j in range(len(board[i])):
                elem = board[i][j]
                row = i
                col = j
                square = (i // 3, j // 3)
                if self.processElem(row,col,square,elem):
                    return False
        return True