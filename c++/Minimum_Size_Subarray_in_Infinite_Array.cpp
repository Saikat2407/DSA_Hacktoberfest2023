// https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxLen(vector<int> &A, int n, int k)
{
    // Your code here
    long sum = 0;
    int ans = 1e9;
    int i = 0, j = 0;
    while (j < n)
    {
        sum = sum + A[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            ans = min(ans, (j - i + 1));
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum = sum - A[i];
                i++;
                if (sum == k)
                {
                    ans = min(ans, (j - i + 1));
                }
            }
            j++;
        }
    }
    return ans;
}
int minSizeSubarray(vector<int> &nums, int target)
{
    long long sum = 0;
    for (auto it : nums)
        sum += it;
    // sum = sum*2;
    ll a = target / sum;
    target %= sum;

    vector<int> v;
    for (auto it : nums)
        v.push_back(it);
    for (auto it : nums)
        v.push_back(it);
    ll ans = maxLen(v, v.size(), target);
    if (ans == 1e9)
        return -1;
    else
        return ans + (a * nums.size());
}
int main()
{

    return 0;
}