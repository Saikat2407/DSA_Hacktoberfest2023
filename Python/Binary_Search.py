def binary_search(my_arr, low, high, x):
 

    if high >= low:
 
        mid = (high + low) // 2
 
        if my_arr[mid] == x:
            return mid
 

        elif my_arr[mid] > x:
            return binary_search(my_arr, low, mid - 1, x)

        else:
            return binary_search(my_arr, mid + 1, high, x)
 
    else:

        return -1
 

my_arr = [ 2, 3, 4, 10, 40 ]
x = 2
 

result = binary_search(my_arr, 0, len(my_arr)-1, x)
 
if result != -1:
    print("Element is present at index", str(result))
else:
    print("Element is not present in array")