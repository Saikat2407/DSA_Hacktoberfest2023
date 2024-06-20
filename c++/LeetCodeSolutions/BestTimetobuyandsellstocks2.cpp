// LEETCODE PROBLEM : 122. Best Time to Buy and Sell Stock II

// LINK TO THE PROBLEM : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day. Find and return the maximum profit you can achieve.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                maxprofit += prices[i] - prices[i - 1];
            }
        }
        return maxprofit;
    }
};

int main() {

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;
    int maxProfit = solution.maxProfit(prices);
    cout << "Max Profit: " << maxProfit << std::endl;

    return 0;
}
