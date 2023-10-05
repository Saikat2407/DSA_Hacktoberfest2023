# Initialize a sample list
my_list = [1, 2, 3, 4, 5]

# 1. Append an element to the end of the list
my_list.append(6)
print("After appending 6:", my_list)

# 2. Insert an element at a specific index
my_list.insert(2, 10)
print("After inserting 10 at index 2:", my_list)

# 3. Remove an element by its value
my_list.remove(4)
print("After removing 4:", my_list)

# 4. Remove an element by its index
element_removed = my_list.pop(0)
print("Element removed at index 0:", element_removed)
print("List after pop:", my_list)

# 5. Find the index of an element by its value
index_of_5 = my_list.index(5)
print("Index of 5:", index_of_5)

# 6. Count occurrences of an element
count_of_3 = my_list.count(3)
print("Count of 3:", count_of_3)

# 7. Sort the list in ascending order
my_list.sort()
print("Sorted list in ascending order:", my_list)

# 8. Reverse the list
my_list.reverse()
print("Reversed list:", my_list)

# 9. Get the length of the list
list_length = len(my_list)
print("Length of the list:", list_length)

# 10. Clear all elements from the list
my_list.clear()
print("List after clearing:", my_list)
