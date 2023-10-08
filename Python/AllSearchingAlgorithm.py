import math

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def jump_search(arr, target):
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0

    while arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

    while arr[prev] < target:
        prev += 1
        if prev == min(step, n):
            return -1

    if arr[prev] == target:
        return prev

    return -1

# Test the searching algorithms
arr = [2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91]

# Element to search
target = 23

# Linear Search
linear_result = linear_search(arr, target)
print("Linear Search Result:", linear_result)

# Binary Search
binary_result = binary_search(arr, target)
print("Binary Search Result:", binary_result)

# Jump Search
jump_result = jump_search(arr, target)
print("Jump Search Result:", jump_result)
