#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* ptr = dummy;
        ListNode* leftptr;

        int dummyLeft = left;

        while (dummyLeft != 1) {
            dummyLeft--;
            leftptr = ptr;
            ptr = ptr->next;
        }

        ListNode* prev = nullptr;
        ListNode* temp;
        ListNode* tail = ptr;

        while (left <= right) {
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
            left++;
        }

        leftptr->next = prev;
        tail->next = ptr;

        return dummy->next;
    }
};

ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }

    cout << "nullptr" << std::endl;
}

int main() {
    Solution solution;

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createLinkedList(arr, n);

    int left = 2;
    int right = 4;

    ListNode* reversedHead = solution.reverseBetween(head, left, right);

    printLinkedList(reversedHead);

    return 0;
}
