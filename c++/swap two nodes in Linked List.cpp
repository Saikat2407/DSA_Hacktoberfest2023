
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

/* Function to swap nodes x and y in linked list by
changing links */
void swapNodes(Node **head_ref, int x, int y)
{
    if (x == y)
        return;

    Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *head_ref = currX;

    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node *start = NULL;

    /* The constructed linked list is:
    1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout << "Linked list before calling swapNodes() ";
    printList(start);

    swapNodes(&start, 4, 3);

    cout << "\nLinked list after calling swapNodes() ";
    printList(start);

    return 0;
}
