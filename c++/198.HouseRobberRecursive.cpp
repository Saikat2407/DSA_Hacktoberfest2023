// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Recursive Approach- UNOPTIMISED
// tIME cOMPLEXITY-> O(2^n)

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int n)
{

    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }
    if (n == 1)
    {
        return nums[1];
    }
    int ans = nums[n] + max(solve(nums, n - 2), solve(nums, n - 3));
    return ans;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    return max(solve(nums, n - 1), solve(nums, n - 2));
}

int main()
{
    vector<int> arr = {2, 7, 9, 3, 1};
    cout << rob(arr);
}