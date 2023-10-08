// Leetcode problem
// https://leetcode.com/problems/sudoku-solver/description/

// Suduko solver using backtracking
class Solution {
    public void solveSudoku(char[][] board) {
        // We are going to need to edit our sudoku board
        solve(board, 0, 0);
    }

    public boolean solve(char[][] board, int row, int col) {
        // If the col is 9, that means you've filled out a whole row. Start the search on the next row by resetting column and incrementing the row by 1
        if (col == board[0].length) {
            col = 0;
            row += 1;
        }

        // If you've reached 9, that means you didn't run into any errors with your blocks in the previous rows, so you have a valid solution
        if (row == board.length) {
            return true; 
        }

        // If this piece already has a value, check the next square
        if (board[row][col] != '.') return solve(board, row, col+1);

        // We want to try every number for this block
        for (char num = '1'; num <= '9'; num++) {
            if (checkIfValid(board, row, col, num)) {
                // Set the value of the current square to the valid num
                board[row][col] = num;

                // Run this algo for the next square over
                boolean solved = solve(board, row, col+1);

                // The only way we can trigger a true is if we got to the end, so if it's true that means we have a solved board so you just keep returning
                if (solved) return true;

                // If our board isn't solved, backtrack and try the next number
                else board[row][col] = '.';
            }
        }

        // You get this when every value of the board is filled, because you don't run anything on it
        // If you get to this step, that means that no values fit, which means the current iteration of the board is wrong so return false and try the previous step again with a different value
        return false;
    }

    public boolean checkIfValid(char[][] board, int row, int col, char value) {
        for (int i = 0; i < board.length; i++) {
            if (board[i][col] == value) return false; // Check the column for duplicates
            if (board[row][i] == value) return false; // Check the row for duplicates
        }

        // This generates our "box", for [1, 1] for example, this pair will be the box bound by [0, 2] and [0,2]
        int boxRow = row / 3;
        int boxCol = col / 3;

        for (int i = boxRow * 3; i < (boxRow + 1) * 3; i++) {
            for (int j = boxCol * 3; j < (boxCol + 1) * 3; j++) {
                // Check the box for duplicates
                if (board[i][j] == value) return false;
            }
        }

		// There are no falses, therefore this is a valid number to put on the square
        return true;
    }
}