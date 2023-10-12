
#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int arr[4] = {12, 32, 21, 15};
    bool Swap = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                Swap = true;
            }
        }

        if (Swap == false)
        {
            break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
