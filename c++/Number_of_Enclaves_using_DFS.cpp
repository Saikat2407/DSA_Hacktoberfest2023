// GFG Problem :- Number Of Enclaves
// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

/* Problem Statement :-
given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves. 

*/

// Solution :-

#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
    void dfs(int row, int col,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        vis[row][col] = true;
        grid[row][col] = -1;
        // Upword direction
        if((row-1)>=0 && grid[row-1][col]==1 && vis[row-1][col]==false){
            dfs(row-1,col,grid,vis);
        }
        // downword direction
        if((row+1)<grid.size() && grid[row+1][col]==1 && vis[row+1][col]==false){
            dfs(row+1,col,grid,vis);
        }
        
        // Left word direction
        
        if((col-1)>=0 && grid[row][col-1]==1 && vis[row][col-1]==false){
            dfs(row,col-1,grid,vis);
        }
        
        // Right word direction
        if((col+1)<grid[0].size() && grid[row][col+1]==1 && vis[row][col+1]==false){
            dfs(row,col+1,grid,vis);
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
         
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        // All are not visited at initial stage
        
        // For first row
        for(int i=0;i<col;i++){
            if(grid[0][i]==1 && vis[0][i]==false){
                dfs(0,i,grid,vis);
            }
        }
        
        // Last row 
            for(int i=0;i<col;i++){
            if(grid[row-1][i]==1 && vis[row-1][i]==false){
                dfs(row-1,i,grid,vis);
            }
        }
        
        // First column
         for(int i=0;i<row;i++){
            if(grid[i][0]==1 && vis[i][0]==false){
                dfs(i,0,grid,vis);
            }
        }
        
        // Last coumn
            for(int i=0;i<row;i++){
            if(grid[i][col-1]==1 && vis[i][col-1]==false){
                dfs(i,col-1,grid,vis);
            }
        }
        
        
        int ans =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl; 
}
