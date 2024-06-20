//Approach-1 (Recur + Memoization) : O(m*n)
class Solution {
public:
    int MPS(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& t) {
        if(i == m-1 && j == n-1)
            return t[i][j] = grid[i][j];
        if(t[i][j] != -1)
            return t[i][j];
        if(i == m-1) { //we can only go right
            return t[i][j] = grid[i][j] + MPS(grid, i, j+1, m, n, t);
        } else if(j == n-1) { //we can go only down
            return t[i][j] = grid[i][j] + MPS(grid, i+1, j, m, n, t);
        } else {
            return t[i][j] = grid[i][j] + min(MPS(grid, i+1, j, m, n, t), MPS(grid, i, j+1, m, n, t));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));
        return MPS(grid, 0, 0, m, n, t);
    }
};
