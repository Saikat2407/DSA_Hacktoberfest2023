# Title: 51. N-Queens (LeetCode)
# Difficulty: Hard
# Problem: https://leetcode.com/problems/n-queens/description/

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def is_valid(board, row, col):
            # Check if there is any queen in the same column or diagonal
            for i in range(row):
                if board[i][col] == 'Q' or (row - i == abs(col - board[i].index('Q'))):
                    return False
            return True

        def backtrack(board, row):
            if row == n:
                res.append([''.join(row) for row in board])
                return
            for col in range(n):
                if is_valid(board, row, col):
                    board[row][col] = 'Q'
                    backtrack(board, row + 1)
                    board[row][col] = '.'

        res = []
        initial_board = [['.' for _ in range(n)] for _ in range(n)]
        backtrack(initial_board, 0)
        return res
