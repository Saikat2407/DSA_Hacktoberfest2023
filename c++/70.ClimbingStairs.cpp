// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#include <iostream>
using namespace std;
int climbStairs(int n)
{
    int arr[n + 2];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n + 2; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n + 1];
}
int main()
{
    cout << climbStairs(4);
}