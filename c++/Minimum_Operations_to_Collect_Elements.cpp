// https://leetcode.com/problems/minimum-operations-to-collect-elements/
#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int> &nums, int k)
{
    set<int> st;
    int cnt = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (st.size() == k)
        {
            return cnt;
        }
        st.insert(nums[i]);

        cnt++;
    }
    return cnt;
}
int main()
{

    return 0;
}