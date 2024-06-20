/*
Ques: Print the power set of the given array
Ex. arr = {1,2,3};
power set of arr: [ [], [1], [2], [3], [1,2], [2,3], [1,3], [1,2,3]]
*/

#include <iostream>
#include <bits\stdc++.h>
using namespace std;

void solve(vector<int> arr, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(arr, output, index + 1, ans);

    // include
    int element = arr[index];
    output.push_back(element);
    solve(arr, output, index + 1, ans);
}

vector<vector<int>> powerSet(vector<int> arr)
{
    vector<int> output;
    vector<vector<int>> ans;
    int index = 0;
    solve(arr, output, index, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    vector<vector<int>> power_set = powerSet(arr);
    cout << "Given Set\n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << " , ";
    }
    cout << " ]" << endl
         << "Power Set\n";
    cout << "[ ] , ";
    int num = pow(2, n);
    for (int i = 1; i < num; i++)
    {
        int j = power_set[i].size();
        cout << "[ ";
        for (int k = 0; k < j; k++)
        {
            cout << power_set[i][k] << " ";
            if (k < j - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < num - 1)
        {
            cout << " , ";
        }
    }
    return 0;
}
