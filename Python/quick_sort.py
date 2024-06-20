# Quick Sort
def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]  # Choose the middle element as the pivot
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right) # recursively calling quick_sort function

# Hard code (input)
my_list = [64, 25, 12, 22, 11]
sorted_list = quick_sort(my_list) # call the function for input array
print("Sorted list:", sorted_list)
