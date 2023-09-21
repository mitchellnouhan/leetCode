class Solution(object):
    def isValidSudoku(self, board):
        rowMap = defaultdict(set)
        colMap = defaultdict(set)
        squareMap = defaultdict(set)
        
        for row in range(len(board)):
            for col in range(len(board)):
                if board[row][col] == '.':
                    continue
                
                if (board[row][col] in rowMap[row] or
                    board[row][col] in colMap[col] or
                    board[row][col] in squareMap[tuple([row // 3, col // 3])]):
                    return False
                
                rowMap[row].add(board[row][col])
                colMap[col].add(board[row][col])
                squareMap[tuple([row // 3, col // 3])].add(board[row][col])
        return True