// problem statement : https://leetcode.com/problems/knight-probability-in-chessboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> moves{{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    vector<vector<vector<double>>> dp;
    int n;

    bool isValid(int x, int y)
    {
        return (x >= 0 && x < n && y >=0 && y < n);
    }

    double knightProbability(int n, int k, int row, int column) {
        this->n=n;
        dp.resize(n, vector<vector<double>> (n, vector<double>(k+1,-1)));
        return func(k,row,column);
    }

    double func(int k, int row, int column)
    {
        if(k==0)    return 1;
        if(dp[row][column][k] != -1)    return dp[row][column][k];
        double ans = 0;
        for(auto [a,b] : moves)
        {
            int x = row+a, y = column+b; 
            if(isValid(x, y))
            {
                ans += 0.125 * func(k-1,x,y);
            }
        }
        return dp[row][column][k] = ans;
    }
};