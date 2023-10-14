// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// TC: O(N)
// SC: O(1)

// Same as House Robber 1, just made two cases:
// 1. From first house to n-1 th house
// 2. From 2nd house to nth house
// So that there is no case where House one and House last both count.

#include <iostream>
#include <vector>
using namespace std;
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
    for (int i = 2; i < n - 1; i++)
    {
        curr = nums[i];
        curr = curr + max(a, b);
        a = b;
        b = c;
        c = curr;
    }
    int max1 = max(curr, b);
    a = 0;
    b = nums[1];
    c = nums[2];
    curr = nums[3];
    for (int i = 3; i < n; i++)
    {
        curr = nums[i];
        curr = curr + max(a, b);
        a = b;
        b = c;
        c = curr;
    }
    int max2 = max(curr, b);
    return max(max1, max2);
}
int main()
{
    vector<int> arr = {2, 7, 9, 3, 1};
    cout << rob(arr);
}