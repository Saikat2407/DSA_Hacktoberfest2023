#include <iostream>
using namespace std;

int partitionArray(int input[], int low, int high)
{

    int pivot = input[low];
    int i = low;
    int j = high;

    while (i < j)
    {

        // find largest element than the pivot from the left
        while (input[i] <= pivot && i <= high)
        {
            i++;
        }

        // find the smallest element from the right of the pivot
        while (input[j] > pivot && j >= low)
        {
            j--;
        }

        if (i < j)
        {
            swap(input[i], input[j]);
        }
    }

    swap(input[low], input[j]);

    return j;
}

void quickSort(int input[], int low, int high)
{

    if (low < high)
    {

        int partition_index = partitionArray(input, low, high);

        // left of the partition
        quickSort(input, low, partition_index - 1);
        quickSort(input, partition_index + 1, high);
    }
}

int main()
{

    int input[9] = {50, 40, 20, 10, 50, 10, 70, 60, 80};

    quickSort(input, 0, 8);

    for (int i = 0; i <= 8; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}