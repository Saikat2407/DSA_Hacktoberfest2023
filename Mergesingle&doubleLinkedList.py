class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

def merge_linked_lists(list1, list2):
    merged_list = LinkedList()
    current1 = list1.head
    current2 = list2.head

    while current1 is not None and current2 is not None:
        if current1.data < current2.data:
            merged_list.append(current1.data)
            current1 = current1.next
        else:
            merged_list.append(current2.data)
            current2 = current2.next

    while current1 is not None:
        merged_list.append(current1.data)
        current1 = current1.next

    while current2 is not None:
        merged_list.append(current2.data)
        current2 = current2.next

    return merged_list

# Example usage
if __name__ == "__main__":
    # Create two singly linked lists
    linked_list1 = LinkedList()
    linked_list1.append(1)
    linked_list1.append(3)
    linked_list1.append(5)

    linked_list2 = LinkedList()
    linked_list2.append(2)
    linked_list2.append(4)
    linked_list2.append(6)

    # Merge the singly linked lists
    merged_singly_linked_list = merge_linked_lists(linked_list1, linked_list2)

    # Print the merged singly linked list
    print("Merged Singly Linked List:")
    merged_singly_linked_list.print_list()

    # Create two doubly linked lists
    class DoublyNode:
        def __init__(self, data):
            self.data = data
            self.prev = None
            self.next = None

    class DoublyLinkedList:
        def __init__(self):
            self.head = None

        def append(self, data):
            new_node = DoublyNode(data)
            if not self.head:
                self.head = new_node
                return
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
            new_node.prev = current

    doubly_linked_list1 = DoublyLinkedList()
    doubly_linked_list1.append(10)
    doubly_linked_list1.append(20)
    doubly_linked_list1.append(30)

    doubly_linked_list2 = DoublyLinkedList()
    doubly_linked_list2.append(15)
    doubly_linked_list2.append(25)
    doubly_linked_list2.append(35)

    # Merge the doubly linked lists
    merged_doubly_linked_list = merge_linked_lists(doubly_linked_list1, doubly_linked_list2)

    # Print the merged doubly linked list
    print("\nMerged Doubly Linked List:")
    current = merged_doubly_linked_list.head
    while current:
        print(current.data, end=" <-> ")
        current = current.next
    print("None")
