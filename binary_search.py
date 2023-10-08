def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2  # Calculate the middle index

        if arr[mid] == target:
            return mid  # Element found, return its index
        elif arr[mid] < target:
            left = mid + 1  # Adjust the left boundary
        else:
            right = mid - 1  # Adjust the right boundary

    return -1  # Element not found in the array

# Example usage
if __name__ == "__main__":
    # Sorted array
    arr = [1, 3, 5, 7, 9, 11, 13, 15, 17]

    # Target element to search for
    target = 7

    # Perform binary search
    result = binary_search(arr, target)

    if result != -1:
        print(f"Element {target} found at index {result}")
    else:
        print(f"Element {target} not found in the array")
