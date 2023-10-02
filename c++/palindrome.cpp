// Leet-Code Problem: 
// https://leetcode.com/problems/palindrome-linked-list/

// Given the head of a singly linked list, return true if it is a  palindrome or false otherwise.

// Solution: 

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true; // An empty list or a list with one node is a palindrome.
        }

        // Helper function to reverse a linked list
        ListNode* reverseList(ListNode* node) {
            ListNode* prev = nullptr;
            while (node) {
                ListNode* temp = node->next;
                node->next = prev;
                prev = node;
                node = temp;
            }
            return prev;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the linked list using slow and fast pointers
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        ListNode* reversedHead = reverseList(slow);

        // Compare the first half and the reversed second half of the linked list
        while (reversedHead) {
            if (head->val != reversedHead->val) {
                return false;
            }
            head = head->next;
            reversedHead = reversedHead->next;
        }

        return true;
    }
};

int main() {
    // Example usage
    // Create a palindrome linked list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution solution;
    bool isPalindrome = solution.isPalindrome(head);

    if (isPalindrome) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Clean up allocated memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
