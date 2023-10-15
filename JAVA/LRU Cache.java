// Problem : https://leetcode.com/problems/lru-cache/
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

/* Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Below is the solution:
*/ 
class LRUCache {
    final Node head = new Node(); // node instance for the head of the doubly linked list
    final Node tail = new Node(); //node instance for the tail of the doubly linked list
    Map<Integer, Node> hm; // hashmap to store key-value pairs (with node references)
    int cache_cap; 

    public LRUCache(int capacity) {
        hm = new HashMap(capacity);
        this.cache_cap = capacity; 
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        int res = -1;
        Node node = hm.get(key); // Get node associated with the given key from HashMap
        if (node != null) { 
            res = node.val; 
            remove(node); // remove the node from current position
            add(node); // add node to the front
        }
        return res;
    }
    
    public void put(int key, int value) {
        Node node = hm.get(key);
        if (node != null) {
            node.val = value;
            remove(node); // remove the node from its current position
            add(node); // add the node to the front
        } else { 
            if (hm.size() == cache_cap) {
                hm.remove(tail.prev.key); // remove the least recently used node from the HashMap.
                remove(tail.prev); // remove the least recently used node from the linked list.
            }
            Node newNode = new Node();
            newNode.key = key;
            newNode.val = value;
            hm.put(key, newNode);
            add(newNode);
        }
    }
    
    public void add(Node node) {
        Node head_next = head.next; // store the current next node of the head.
        node.next = head_next; // set the next node of the new node to the current next node of the head.
        head_next.prev = node; // set the previous node of the current next node of the head to the new Node.
        head.next = node; // set the next node of the head to the new node (new node becomes the first node).
        node.prev = head; // set the previous node of the new node to the head.
    }
    
    public void remove(Node node) { // helper method to remove a node from the doubly linked list.
        Node next_node = node.next; // store the next node of the node to be removed.
        Node prev_node = node.prev; // store the previous node of the node to be removed.
        next_node.prev = prev_node; // set the previous node of the next node to the previous node of the node.
        prev_node.next = next_node; // set the next node of the previous node to the next node of the node.
    }
    
    class Node {
        int key;
        int val;
        Node prev;
        Node next;
    }
}
