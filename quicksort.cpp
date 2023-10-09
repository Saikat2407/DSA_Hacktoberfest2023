#include <stdio.h>
#include <stdlib.h>
 
#define SWAP(x, y) { int temp = x; x = y; y = temp; }
#define N (sizeof(nums)/sizeof(nums[0]))
 
// Partition using Lomuto partition scheme
int partition(int a[], int left, int right, int pIndex)
{
    // pick `pIndex` as a pivot from the array
    int pivot = a[pIndex];
 
    // Move pivot to end
    SWAP(a[pIndex], a[right]);
 
    // elements less than the pivot will be pushed to the left of `pIndex`;
    // elements more than the pivot will be pushed to the right of `pIndex`;
    // equal elements can go either way
    pIndex = left;
 
    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = left; i < right; i++)
    {
        if (a[i] <= pivot)
        {
            SWAP(a[i], a[pIndex]);
            pIndex++;
        }
    }
 
    // move pivot to its final place
    SWAP(a[pIndex], a[right]);
 
    // return `pIndex` (index of the pivot element)
    return pIndex;
}
 
// Returns the k'th smallest element in the list within `left…right`
// (i.e., left <= k <= right). The search space within the array is
// changing for each round – but the list is still the same size.
// Thus, `k` does not need to be updated with each round.
int quickselect(int nums[], int left, int right, int k)
{
    // If the array contains only one element, return that element
    if (left == right) {
        return nums[left];
    }
 
    // select `pIndex` between left and right
    int pIndex = left + rand() % (right - left + 1);
 
    pIndex = partition(nums, left, right, pIndex);
 
    // The pivot is in its final sorted position
    if (k == pIndex) {
        return nums[k];
    }
 
    // if `k` is less than the pivot index
    else if (k < pIndex) {
        return quickselect(nums, left, pIndex - 1, k);
    }
 
    // if `k` is more than the pivot index
    else {
        return quickselect(nums, pIndex + 1, right, k);
    }
}
 
int main()
{
    int nums[] = { 7, 4, 6, 3, 9, 1 };
    int k = 2;
 
    printf("k'th smallest element is %d", quickselect(nums, 0, N - 1, k - 1));
 
    return 0;
}
