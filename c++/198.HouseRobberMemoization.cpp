// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Tabulation
// Time Complexity-> O(n)

#include <iostream>
#include <vector>
using namespace std;

// Space Complexiy-> O(1) wohooo
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    if (n == 2)
    {
        return max(nums[0], nums[1]);
    }
    int a = 0;
    int b = nums[0];
    int c = nums[1];
    int curr = nums[2];
    for (int i = 2; i < n; i++)
    {
        curr = nums[i];
        curr = curr + max(a, b);
        a = b;
        b = c;
        c = curr;
    }
    return max(curr, b);
}

int main()
{
    vector<int> arr = {2, 7, 9, 3, 1};
    cout << rob(arr);
}

//---------------------Beats 100% TC on Leetcode but not Space Optimised----------------------------------------

// Space complexity -> O(n)
//  int rob(vector<int> &nums)
//  {
//      int n = nums.size();
//      if (n == 1)
//      {
//          return nums[0];
//      }
//      if (n == 2)
//      {
//          return max(nums[0], nums[1]);
//      }
//      vector<int> dp(n + 1, 0);
//      dp[0] = 0;
//      dp[1] = nums[0];
//      dp[2] = nums[1];
//      for (int i = 3; i < n + 1; i++)
//      {
//          dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i - 1];
//      }
//      return max(dp[n - 1], dp[n]);
//  }

//----------------------Wont Work on Leetcode but will work  on VSCode Soln-------------------------------------

// int rob(vector<int> &nums)
// {
//  int n = nums.size();
// if (n == 1)
// {
//     return nums[0];
// }
// if (n == 2)
// {
//     return max(nums[0], nums[1]);
// }
//     int n = nums.size();
//     vector<int> dp(n + 2, -1);
//     dp[0] = nums[0];
//     dp[1] = nums[1];

//     for (int i = 2; i < n; i++)
//     {
//         dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
//     }
//     return max(dp[n - 2], dp[n - 1]);
// }
