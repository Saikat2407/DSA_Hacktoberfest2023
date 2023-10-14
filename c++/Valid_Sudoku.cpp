// Leetcode Problem: https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), blocks(9);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') { continue; }

                int curr = board[i][j];

                if(rows[i].count(curr) || cols[j].count(curr) || blocks[3 * (i/3) + (j/3)].count(curr)) {
                    return false;
                }

                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[3 * (i/3) + (j/3)].insert(curr);
            }
        }

        return true;
    }
};

// Time Complexity: O(1) -> The size of the board is fixed so our loops will always execute 81 times in the worst case
// Space Complexity O(1) -> Yes, we create a vector, but the size of the vector is static

/*
    Intuition:

    We want to traverse each row and check to see if our sets already contain the value
    encountered at the specified index. If so, then we can immediately return false 
    because there are no duplicate values allowed in a specific row and column in a 
    valid sudoku. If it doesn't already contain the value encountered, then we can
    just add it to the sets and continue on until we reach the end of our matrix.

*/