class Solution(object):
    def solveNQueens(self, n):
        self.col = [0]*n
        self.left = [0]*(2*n-1)
        self.right = [0]*(2*n-1)
        board = [['.' for x in range(n)] for y in range(n)]
        self.resultBoard = []
        self.backTrack(n, 0, board)
        return self.resultBoard

    def backTrack(self, n, level, board):
        if level == n:
            res = []
            for i in range(n):
                res.append(''.join(board[i]))
            self.resultBoard.append(res)
            return
        for i in range(n):
            if not self.col[i] and not self.left[level-i] and not self.right[level+i]:
                board[level][i] = 'Q'
                self.col[i] = 1
                self.left[level-i] = 1
                self.right[level+i] = 1
                self.backTrack(n, level+1, board)
                board[level][i] = '.'
                self.col[i] = 0
                self.left[level-i] = 0
                self.right[level+i] = 0
