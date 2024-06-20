#include <stdio.h>
void merge(int arr[], int l, int mid, int h)
{
    int size = h;
    int b[size++], k = l, i = l, j = mid + 1;

    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            b[k++] = arr[i++];
        }
        else
        {
            b[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = arr[i++];
    }
    while (j <= h)
    {
        b[k++] = arr[j++];
    }

    for (int n = l; n <= h; n++)
    {
        arr[n] = b[n];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int l = low, h = high;

    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[10] = {12, 4, 54, 3, 6, 34, 23, 10, 2, 5};
    mergeSort(arr, 0, 9);

    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}