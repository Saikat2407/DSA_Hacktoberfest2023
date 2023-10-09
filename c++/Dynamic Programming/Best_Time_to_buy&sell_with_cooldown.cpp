//Leetcode 309. Best Time to Buy and Sell Stock with Cooldown

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include <bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0; buy<=1;buy++){
                if(buy){
                    dp[i][buy]=max(-prices[i] +dp[i+1][0] , dp[i+1][1]);

                }
                else{
                    
                        dp[i][buy]=max(prices[i] + dp[i+2][1], dp[i+1][0]);

                    }
                    
                }
            }
        
        return dp[0][1];
    }
};