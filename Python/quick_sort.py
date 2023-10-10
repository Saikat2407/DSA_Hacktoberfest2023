def partition(array, low, high):
    pivot = array[high]
    i = low - 1
 
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
 
    (array[i + 1], array[high]) = (array[high], array[i + 1])
 
    return i + 1
 
def quickSort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
 
        quickSort(array, low, pi - 1)
 
        quickSort(array, pi + 1, high)
 

n = int(input("Number of elements - "))
l = []

for i in range(n):
    a = int(input("Enter the element - "))
    l.append(a)
    
print("Unsorted Array")
print(l)
 
size = len(l)
 
quickSort(l, 0, size - 1)
 
print('Sorted Array in Ascending Order:')
print(l)
