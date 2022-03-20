class Solution:
    def checkSurrBoard(self, board: List[List[str]], sr: int, sc: int) -> False:
        m = len(board)
        n = len(board[0])
        if sr >= m or sc >= n or sr < 0 or sc < 0:
            return False
        Flag = True
        if board[sr][sc] == 'O':
            board[sr][sc] = 'V'
            Flag &= sr != 0
            Flag &= sc != 0
            Flag &= self.checkSurrBoard(board, sr+1, sc)
            Flag &= self.checkSurrBoard(board, sr-1, sc)
            Flag &= self.checkSurrBoard(board, sr, sc-1)
            Flag &= self.checkSurrBoard(board, sr, sc+1)
            return Flag
        return True

    def markBoard(self, board: List[List[str]], sr: int, sc: int, c: str):
        m = len(board)
        n = len(board[0])
        if sr >= m or sc >= n:
            return
        if board[sr][sc] == 'V':
            board[sr][sc] = c
            self.markBoard(board, sr+1, sc, c)
            self.markBoard(board, sr, sc+1, c)
            self.markBoard(board, sr, sc-1, c)
            self.markBoard(board, sr-1, sc, c)

    
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'O' and self.checkSurrBoard(board, i, j):
                    print(i, j)
                    self.markBoard(board, i, j, 'X')
        # print(board)            
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'V':
                    board[i][j] = 'O'        
