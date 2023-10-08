#include <bits/stdc++.h>
using namespace std;

bool isSubsetPossible(int arr[], int n, int sum)
{
    bool t[n + 1][sum + 1]; // DP - matrix
    // initialization
    // here we are setting 1st row and 1st column
    // i denotes the size of the array
    // j denotes the target sum (subset sum)
    for (int i = 0; i <= n; i++)
    { // itereate as long it is less then length of the array
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0) // when array(i) is empty than there is no meaning of sum of elements so return false
                t[i][j] = false;
            if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return it as true;
                t[i][j] = true;
        }
    }
    // start from 1 since 1st row and column is already considerd
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                // after taking and element substract from the (sum) i.e -> in {3,8} 3 is taken then we want 11-3=8in the array
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // either take or(||) do not take
            else                                                   // if sum is less than array size just leave and increment
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum]; // at last return T/F
}

bool EqualSumPartitionPossible(int arr[], int n)
{
    int sum = 0;                // sum of all elements of arr
    for (int i = 0; i < n; i++) // take the sum of array
        sum += arr[i];

    if (sum % 2 != 0) // if sum is odd --> not possible to make equal partitions
        return false;

    return isSubsetPossible(arr, n, sum / 2); // when even divide sum of array into two part and apply subset sum
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    EqualSumPartitionPossible(arr, n) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
