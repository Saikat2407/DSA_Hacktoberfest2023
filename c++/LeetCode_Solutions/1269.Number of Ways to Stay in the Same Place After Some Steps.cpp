// Problem Link:https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/ 

// 15-10-23(POTD)

// Space Optimized Dp Solution:

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int MOD = 1e9 + 7;
        arrLen = min(arrLen, steps);
        vector<int> dp(arrLen, 0);
        vector<int> prevDp(arrLen, 0);
        prevDp[0] = 1;
        
        for (int remain = 1; remain <= steps; remain++) {
            dp=vector<int>(arrLen,0);
            
            for (int curr = arrLen - 1; curr >= 0; curr--) {
                int ans = prevDp[curr];
                
                if (curr > 0) {
                    ans = (ans + prevDp[curr - 1]) % MOD;
                }
                
                if (curr < arrLen - 1) {
                    ans = (ans + prevDp[curr + 1]) % MOD;
                }
                
                dp[curr] = ans;
            }
            
            prevDp = dp;
        }
        
        return dp[0];
    }
};