# Tim Sort implementation in Python

# The size of a run (a small chunk of the array to be sorted)
RUN = 32

# Insertion sort is used to sort small runs
def insertion_sort(arr, left=0, right=None):
    if right is None:
        right = len(arr) - 1

    for i in range(left + 1, right + 1):
        key_item = arr[i]
        j = i - 1
        while j >= left and arr[j] > key_item:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key_item

# Merge function to merge two sorted runs
def merge(arr, left, mid, right):
    len1, len2 = mid - left + 1, right - mid
    left_half, right_half = [], []
    for i in range(0, len1):
        left_half.append(arr[left + i])
    for i in range(0, len2):
        right_half.append(arr[mid + 1 + i])

    i, j, k = 0, 0, left

    while i < len1 and j < len2:
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1
        k += 1

    while i < len1:
        arr[k] = left_half[i]
        k += 1
        i += 1

    while j < len2:
        arr[k] = right_half[j]
        k += 1
        j += 1

# Implementation of Tim Sort
def tim_sort(arr):
    n = len(arr)
    for i in range(0, n, RUN):
        insertion_sort(arr, i, min((i + RUN - 1), (n - 1)))

    size = RUN
    while size < n:
        for left in range(0, n, 2 * size):
            mid = min((left + size - 1), (n - 1))
            right = min((left + 2 * size - 1), (n - 1))

            if mid < right:
                merge(arr, left, mid, right)

        size = 2 * size

if __name__ == "__main__":
  
    arr = [5, 21, 7, 23, 19, 6]
    print("Original Array: ", arr)
    tim_sort(arr)
    print("Sorted Array: ", arr)
