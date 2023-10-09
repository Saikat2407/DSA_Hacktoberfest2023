// Leetcode 63. Unique Paths II

// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

 //Link : - https://leetcode.com/problems/unique-paths-ii/description/
#include <bits/stdc++.h>

 class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>> &dp){
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        if(obstacleGrid[row][col]==1)return 0;
        int left=solve(obstacleGrid,row,col-1,dp);
        int up=solve(obstacleGrid,row-1,col,dp);
        dp[row][col]=left+up;
        return dp[row][col];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
         if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
        if(m==1 && n==1)return 1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
       int ans= solve(obstacleGrid,m-1,n-1,dp);
       return ans;
    }
};