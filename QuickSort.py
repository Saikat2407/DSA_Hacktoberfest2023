def partition(arr, start, end):
    pivot = arr[start]
    count = 0
    for i in range(start + 1, end + 1):
        if arr[i] <= pivot:
            count += 1

    pivot_index = start + count
    arr[pivot_index], arr[start] = arr[start], arr[pivot_index]

    i, j = start, end
    while i < pivot_index and j > pivot_index:
        while arr[i] <= pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1

        if i < pivot_index and j > pivot_index:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

    return pivot_index

def quick_sort(arr, start, end):
    if start >= end:
        return

    p = partition(arr, start, end)
    quick_sort(arr, start, p - 1)
    quick_sort(arr, p + 1, end)

if __name__ == "__main__":
    arr = [9, 3, 4, 2, 1, 8]
    n = len(arr)

    quick_sort(arr, 0, n - 1)

    for i in range(n):
        print(arr[i], end=" ")
































