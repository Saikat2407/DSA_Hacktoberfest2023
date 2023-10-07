/* Hackerrank problem

Link: https://www.hackerrank.com/challenges/the-birthday-bar/problem

*/

#include <iostream>
using namespace std;

int birthday(int arr[], int n, int d, int m)
{
    int ways = 0;

    for (int i = 0; i <= n - m; i++)
    {
        int sum = 0;
        for (int j = i; j < i + m; j++)
            sum += arr[j];

        // Check if the sum equals the birth-day. Increment number of ways.
        if (sum == d)
            ways++;
    }

    return ways;
}

int main()
{
    int size, d, m;

    cout << "Enter size of an array: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }

    cout << "Enter birthday: ";
    cin >> d;

    cout << "Enter birth-month: ";
    cin >> m;

    int result = birthday(arr, size, d, m);
    cout << "Result: " << result << endl;

    return 0;
}