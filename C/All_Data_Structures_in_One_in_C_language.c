// Hardik Kushwaha
// Developed By: Hardik Kushwaha

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// *******************************************************
// 1. Array
#define MAX 20
int array[MAX], n=0;
void MyArray();
void insertionMyArray();
void displayMyArray();
void deletionMyArray();
void searchingMyArray(); 
void sortingMyArray();
// *******************************************************
// 2. Singly Linked List
void MyList();
void insertAtBeginingMyList(int);
void insertAtPositionMyList();
void insertAtLastMyList(int);
void deleteFromBeginingMyList();
void deleteFromPositionMyList();
void deleteFromLastMyList();
void displayMyList();
int lengthMyList();
int element, pos; 
struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;
// *******************************************************
// 3. Doubly Linked List
void MyDoublyList();
void insertAtBeginingMyDoublyList(int);
void insertAtPositionMyDoublyList();
void insertAtLastMyDoublyList(int);
void deleteFromBeginingMyDoublyList();
void deleteFromPositionMyDoublyList();
void deleteFromLastMyDoublyList();
void displayMyDoublyList();
int lengthMyDoublyList();
struct dnode {
    int data;
    struct dnode *prev, *next;
};
struct dnode *dhead = NULL;
// *******************************************************
// 4. Circular Linked List
void MyCircularList();
void insertAtBeginingMyCircularList(int);
void insertAtPositionMyCircularList();
void insertAtLastMyCircularList(int);
void deleteFromBeginingMyCircularList();
void deleteFromPositionMyCircularList();
void deleteFromLastMyCircularList();
void displayMyCircularList();
int lengthMyCircularList();
struct cnode {
    int data;
    struct cnode *next;
};
struct cnode *tail = NULL;
// *******************************************************
// 5. Array Implementation of Array
#define StackMax 20
int top = -1, stack[StackMax];
void MyArrayStack();
void pushMyArrayStack();
void popMyArrayStack();
void topMyArrayStack();
void displayMyArrayStack();
// *******************************************************
// 6. Linked List Implementation of Stack
#define MaxStack 20
void MyListStack();
void pushMyListStack();
void popMyListStack();
void topMyListStack();
void displayMyListStack();
int lengthMyListStack=0; 
struct snode {
    int data;
    struct snode *link;
};
struct snode *shead = NULL;
// *******************************************************
// 7. Array Implementation of Queue
#define MaxQueue 20
int queue[MaxQueue], front = -1, rear = -1;
void MyArrayQueue();
void enqueueMyArrayQueue();
void dequeueMyArrayQueue();
void displayMyArrayQueue();
// *******************************************************
// 8. Linked List Implementation of Queue
void MyListQueue();
void enqueueMyListQueue();
void dequeueMyListQueue();
void displayMyListQueue();
int lengthMyListQueue=0; 
struct qnode {
    int data;
    struct qnode *link;
};
struct qnode *listfront =NULL, *listrear = NULL;
// *******************************************************
// 9. Array Implementation of Doubly Ended Queue
int deque[MaxQueue];
void MyArrayDeque();
void enqueueAtRearMyArrayDeque();
void dequeueAtFrontMyArrayDeque();
void enqueueAtFrontMyArrayDeque();
void dequeueAtRearMyArrayDeque();
void displayMyArrayDeque();
// *******************************************************
// 10. Stack Implementation of Queue
int stack1[MaxQueue], stack2[MaxQueue];
int top1 = -1, top2 = -1, lengthMyStackQueue = 0;
void MyStackQueue();
void push1MyStackQueue(int element);
void push2MyStackQueue(int element);
int pop1MyStackQueue();
int pop2MyStackQueue();
void enqueueMyStackQueue();
void dequeueMyStackQueue();
void displayMyStackQueue();
// *******************************************************
// 11. Array Implementation of Binary Search Tree
#define MaxBST 50
int bst[MaxBST] = {0}, totalNodesMyArrayBST = 0, rootArray = 1;
void MyArrayBST();
void insertMyArrayBST();
void displayMyArrayBST();
void preorderTraversalMyArrayBST();
void inorderTraversalMyArrayBST();
void postorderTraversalMyArrayBST();
void searchingMyArrayBST();
// *******************************************************
// 12. Linked List Implementation of Binary Search Tree
void MyListBST();
void insertMyListBST();
void deleteMyListBST();
void displayMyListBST();
void preorderTraversalMyListBST();
void inorderTraversalMyListBST();
void postorderTraversalMyListBST();
void searchingMyListBST();
struct bstNode {
    int data;
    struct bstNode *left, *right;
};
struct bstNode *root = NULL;
int totalNodesMyListBST = 0;
// *******************************************************

int main() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|                 All Data Structures in One Program               |");
        printf("\n|                                                                  |");
        printf("\n|   1.  Array Implementation                                       |");
        printf("\n|   2.  Linked List Implementation                                 |");
        printf("\n|   3.  Stack Implementation                                       |");
        printf("\n|   4.  Queue Implementation                                       |");
        printf("\n|   5.  Binary Search Tree Implementation                          |");
        printf("\n|   6.  Exit                                                       |");
        printf("\n ------------------------------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {                                      // Hardik Kushwaha
            case 1:
                MyArray();
                break;
            case 2:
                do {
                    printf("\n ------------------------------------------------------------------");
                    printf("\n|                   Linked List Implementation                     |");
                    printf("\n|                                                                  |");
                    printf("\n|   1.  Singly Linked List  Implementation                         |");
                    printf("\n|   2.  Doubly Linked List  Implementation                         |");
                    printf("\n|   3.  Circular Linked List  Implementation                       |");
                    printf("\n|   4.  Exit                                                       |");
                    printf("\n ------------------------------------------------------------------");
                    printf("\nEnter your choice: ");
                    scanf("%d",&choice);
                    switch (choice) {
                        case 1:
                            MyList();
                            break;
                        case 2:
                            MyDoublyList();
                            break;
                        case 3:
                            MyCircularList();
                            break;
                        case 4:
                            printf("Exited successfully!\n");
                            break;
                        default:
                            printf("Invalid choice!\n");
                            break;
                    }
                } while (choice != 4);
                break;
            case 3:
                do {
                        printf("\n ------------------------------------------------------------------");
                        printf("\n|                      Stack Implementation                        |");
                        printf("\n|                                                                  |");
                        printf("\n|   1.  Array Implementation of Stack                              |");
                        printf("\n|   2.  Linked List Implementation of Stack                        |");
                        printf("\n|   3.  Exit                                                       |");
                        printf("\n ------------------------------------------------------------------");
                        printf("\nEnter your choice: ");
                        scanf("%d",&choice);
                        switch (choice) {
                            case 1:
                                MyArrayStack();
                                break;
                            case 2:
                                MyListStack();
                                break;
                            case 3:
                                printf("Exited successfully!\n");
                                break;
                            default:
                                printf("Invalid choice!\n");
                                break;
                        }
                } while (choice != 3);
                break;
            case 4:
                do {
                    printf("\n ------------------------------------------------------------------");
                    printf("\n|                      Queue Implementation                        |");
                    printf("\n|                                                                  |");
                    printf("\n|   1.  Array Implementation of Queue                              |");
                    printf("\n|   2.  Linked List Implementation of Queue                        |");
                    printf("\n|   3.  Array Implementation of Doubly Ended Queue (Deque)         |");
                    printf("\n|   4.  Stack Implementation of Queue                              |");
                    printf("\n|   5.  Exit                                                       |");
                    printf("\n ------------------------------------------------------------------");
                    printf("\nEnter your choice: ");
                    scanf("%d",&choice);
                    switch (choice) {
                        case 1:
                            MyArrayQueue();
                            break;
                        case 2:
                            MyListQueue();
                            break;
                        case 3:
                            MyArrayDeque();
                            break;
                        case 4:
                            MyStackQueue();
                            break;
                        case 5:
                            printf("Exited successfully!\n");
                            break;
                        default:
                            printf("Invalid choice!\n");
                            break;
                    }
                } while (choice != 5);
                break;
            case 5:
                do {
                    printf("\n ------------------------------------------------------------------");
                    printf("\n|                 Binary Search Tree Implementation                |");
                    printf("\n|                                                                  |");
                    printf("\n|   1.  Array Implementation of BST                                |");
                    printf("\n|   2.  Linked List Implementation of BST                          |");
                    printf("\n|   3.  Exit                                                       |");
                    printf("\n ------------------------------------------------------------------");
                    printf("\nEnter your choice: ");
                    scanf("%d",&choice);
                    switch (choice) {
                        case 1:
                            MyArrayBST();
                            break;
                        case 2:
                            MyListBST();
                            break;
                        case 3:
                            printf("Exited successfully!\n");
                            break;
                        default:
                            printf("Invalid choice!\n");
                            break;
                    }
                } while (choice != 3);
                break;
            case 6:
                printf("Exited successfully!\nDeveloped By: Hardik Kushwaha");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

// 1. Array
void MyArray()
{
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|                     Array Implementation                         |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Searching\n5. Sorting\n6. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {                                      // Hardik Kushwaha
            case 1:
                insertionMyArray();
                break;
            case 2:
                deletionMyArray();
                break;
            case 3:
                displayMyArray();
                break;
            case 4:
                searchingMyArray();
                break;
            case 5:                             // Hardik Kushwaha                       
                sortingMyArray();
                break;
            case 6:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6);
}
void insertionMyArray() {
    if(n == MAX-1) {                            // Hardik Kushwaha
        printf("Array is Full!\n");
        return;
    }

    if(n == 0) {                                // Insertion in empty array
        printf("Enter the size of array: ");
        scanf("%d",&n);
        printf("Enter the elements:\n");
        for(int i=0; i<n; i++) {
            scanf("%d",&array[i]);
        }
        printf("Elements inserted successfully!\n");
        return;
    }

    int element, pos;
    printf("Enter the element: ");              // Insertion at given position
    scanf("%d",&element);
    
    do {
        printf("Enter the valid position: ");
        scanf("%d",&pos);
    } while (pos<=0 || pos>n+1);

    pos--;
    for(int i=n; i>pos; i--) {
        array[i]=array[i-1];
    }                                           // Hardik Kushwaha
    array[pos]=element;
    n++;
    printf("Element inserted successfully!\n");
}
void deletionMyArray() {
    int pos;
    if(n == 0) {
        printf("Empty Array!\n");
        return;
    }       
                                        // Hardik Kushwaha         
    do {
        printf("Enter the valid position: ");
        scanf("%d",&pos);
    } while (pos<=0 || pos>n);

    pos--;
    printf("Element %d deleted successfully!\n",array[pos]);
    for(int i=pos; i<n; i++) {
        array[i]=array[i+1];
    }
    n--;
}
void displayMyArray() {
    if(n == 0) {
        printf("Empty Array!\n");
        return;
    }                                       
                                                // Hardik Kushwaha                                     
    printf("Elements of the array: ");
    for(int i=0; i<n; i++) {
        printf("%d  ",array[i]);
    }
    printf("\n");
}
void searchingMyArray() {
    if(n == 0) {
        printf("Empty Array!\n");
        return;
    }

    int element, condition=0;
    printf("Enter the element: ");              // Searching the element
    scanf("%d",&element);
    for(int i=0; i<n; i++) {
        if(element == array[i]){
            printf("Element found in the array at position %d\n",i+1);
            condition=1;
            break;
        }
    }                                           // Hardik Kushwaha          
    if(condition == 0){
        printf("Element not found in the array\n");
    }
}
void sortingMyArray() {
    if(n == 0) {
        printf("Empty Array!\n");
        return;
    }
                                                // Hardik Kushwaha
    for(int i=0; i<n-1; i++) {                  // Using Bubble Sort
        for(int j=0; j<n-1; j++) {
            if(array[j]>array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("Array is Sorted!\n");
    displayMyArray();
}

// 2. Singly Linked List
void MyList() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|                Singly Linked List Implementation                 |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Total Elements\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertAtPositionMyList();
                break;
            case 2:
               deleteFromPositionMyList();
                break;
            case 3:
                displayMyList();
                break;
            case 4:
                printf("Total elements: %d\n",lengthMyList());
                break;
            case 5:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);
}
void insertAtPositionMyList() {
    struct node *newP=malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d",&element);
    if(head == NULL) {
        newP->data = element;
        newP->link = NULL;
        head = newP;
        printf("Element inserted successfully!\n");
        return;                                 // Hardik Kushwaha
    }

    do {
        printf("Enter the valid position: ");
        scanf("%d",&pos);
    } while(pos<=0 || pos>lengthMyList()+1);
        
    if(pos == 1) {                              // Insertition at front(1st position)
        insertAtBeginingMyList(element);
        return;
    }

    if(pos == lengthMyList()+1) {               // Insertition at last(last position)
        insertAtLastMyList(element);
        return;
    }

    struct node *temp = head;                   // Insertion at given position         
    int i=1;
    while(i<pos-1) {
        temp = temp->link;
        i++;
    }                                           // Hardik Kushwaha          
    newP->data = element;
    newP->link = temp->link;
    temp->link = newP;
    printf("Element inserted successfully!\n");
}
void insertAtBeginingMyList(int element) {
    struct node *newP = malloc(sizeof(struct node));
    newP->data = element;
    newP->link = head;                      // Hardik Kushwaha        
    head = newP;
    printf("Element inserted successfully!\n");
}
void insertAtLastMyList(int element) {
    struct node *newP = malloc(sizeof(struct node));
    struct node *temp = head;
                                            // Hardik Kushwaha
    newP->data = element;
    newP->link = NULL;
    while(temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newP;
    printf("Element inserted successfully!\n");
}
void deleteFromPositionMyList() {
    if(head == NULL) {
        printf("Empty Linked List!\n");
        return;
    }
                                            //Hardik Kushwaha
    do {
        printf("Enter the valid position: ");
        scanf("%d",&pos);
    } while(pos<=0 || pos>lengthMyList());
        
    if(pos == 1) {                          // Deletion from front(1st position)
        deleteFromBeginingMyList();
        return;
    }

    if(pos == lengthMyList()) {             // Deletion from last(last position)
        deleteFromLastMyList();
        return;
    }

    struct node *position = malloc(sizeof(struct node));
    struct node *temp = head;
    int i=1;                                // Deletion from given position
    while(i<pos-1) {
        temp = temp->link;
        i++;
    }
    position = temp->link;                  // Hardik Kushwaha        
    temp->link = position->link;
    printf("Element %d deleted successfully!\n",position->data);
    free(position);
}
void deleteFromBeginingMyList() {
    struct node *temp = head;
    printf("Element %d deleted successfully!\n",temp->data);
    head = head->link;
    free(temp);                             // Hardik Kushwaha
}
void deleteFromLastMyList() {
    struct node *temp = head, *position=malloc(sizeof(struct node));
    int i = 1;
    while(i < lengthMyList()-1) {
        temp = temp->link;
        i++;
    }                                       // Hardik Kushwaha
    position  = temp->link;
    temp->link = NULL;
    printf("Element %d deleted successfully!\n", position->data);
    free(position);
}
int lengthMyList() {
    if(head == NULL) {
        printf("Linked List is Empty!\n");
        return 0;                           // Returns 0 if linked list is empty
    }
    struct node *temp = head;
    int size = 0;                           // Hardik Kushwaha
    while(temp != NULL) {
        temp = temp->link;
        size++;
    }
    return size;                            // Returns the length(total elements) of the linked list
}
void displayMyList() {
    if(head == NULL) {                      // Checks whether linked list is empty or not
        printf("Linked List is Empty!\n");
        return;
    }                                           
    struct node *temp = head;
    printf("Linked List: ");
    while(temp != NULL) {                   // Prints the linked list
        printf("%d  ",temp->data);
        temp = temp->link;
    }                                       // Hardik Kushwaha
    printf("\n");
}

// 3. Doubly Linked List
void MyDoublyList() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|                 Doubly Linked List Implementation                |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Total Elements\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertAtPositionMyDoublyList();
                break;
            case 2:
               deleteFromPositionMyDoublyList();
                break;
            case 3:
                displayMyDoublyList();
                break;
            case 4:
                printf("Total elements: %d\n",lengthMyDoublyList());
                break;
            case 5:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);
}
void insertAtPositionMyDoublyList() {
    struct dnode *newP=malloc(sizeof(struct dnode));
    printf("Enter the element: ");
    scanf("%d",&element);
    if(dhead == NULL) {
        newP->data = element;
        newP->prev = NULL;
        newP->next = NULL;
        dhead = newP;
        printf("Element inserted successfully!\n");
        return;                                 // Hardik Kushwaha
    }

    do {
        printf("Enter the valid position: ");
        scanf("%d",&pos);
    } while(pos<=0 || pos>lengthMyDoublyList()+1);
        
    if(pos == 1) {                              // Insertition at front(1st position)
        insertAtBeginingMyDoublyList(element);
        return;
    }

    if(pos == lengthMyDoublyList()+1) {               // Insertition at last(last position)
        insertAtLastMyDoublyList(element);
        return;
    }

    struct dnode *temp = dhead;                   // Insertion at given position         
    int i=1;
    while(i<pos-1) {
        temp = temp->next;
        i++;
    }                                           // Hardik Kushwaha          
    newP->data = element;
    newP->prev = temp;
    newP->next = temp->next;
    temp->next = newP;
    printf("Element inserted successfully!\n");
}
void insertAtBeginingMyDoublyList(int element) {
    struct dnode *newP = malloc(sizeof(struct dnode));
    newP->data = element;
    newP->prev = NULL;
    newP->next = dhead;                      // Hardik Kushwaha        
    dhead->prev = newP;
    dhead = newP;
    printf("Element inserted successfully!\n");
}
void insertAtLastMyDoublyList(int element) {
    struct dnode *newP = malloc(sizeof(struct dnode));
    struct dnode *temp = dhead;
                                            // Hardik Kushwaha
    newP->data = element;
    newP->next = NULL;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newP;
    newP->prev = temp;
    printf("Element inserted successfully!\n");
}
void deleteFromPositionMyDoublyList() {
    if(dhead == NULL) {
        printf("Empty Linked List!\n");
        return;
    }
                                            //Hardik Kushwaha
    if(lengthMyDoublyList() == 1) {
        struct dnode *temp = dhead;
        printf("Element %d deleted successfully!\n", temp->data);
        dhead = NULL;
        free(temp);
        return;
    }   

    do {
        printf("Enter the valid position: ");
        scanf("%d",&pos);
    } while(pos<=0 || pos>lengthMyDoublyList());
        
    if(pos == 1) {                           // Deletion from front(1st position)
        deleteFromBeginingMyDoublyList();
        return;
    }

    if(pos == lengthMyDoublyList()) {             // Deletion from last(last position)
        deleteFromLastMyDoublyList();
        return;
    }

    struct dnode *position = malloc(sizeof(struct dnode));
    struct dnode *temp = dhead;
    int i=1;                                // Deletion from given position
    while(i<pos-1) {
        temp = temp->next;
        i++;
    }
    position = temp->next;                  // Hardik Kushwaha        
    temp->next = position->next;
    (position->next)->prev = temp;
    printf("Element %d deleted successfully!\n",position->data);
    free(position);
}
void deleteFromBeginingMyDoublyList() {
    struct dnode *temp = dhead;
    printf("Element %d deleted successfully!\n",temp->data);
    dhead = dhead->next;
    dhead->prev = NULL;
    free(temp);                             // Hardik Kushwaha
}
void deleteFromLastMyDoublyList() {
    struct dnode *temp = dhead, *position=malloc(sizeof(struct dnode));
    int i = 1;
    while(i < lengthMyDoublyList()-1) {
        temp = temp->next;
        i++;
    }                                       // Hardik Kushwaha
    position  = temp->next;
    temp->next = NULL;
    printf("Element %d deleted successfully!\n", position->data);
    free(position);
}
int lengthMyDoublyList() {
    if(dhead == NULL) {
        printf("Linked List is Empty!\n");
        return 0;                           // Returns 0 if linked list is empty
    }
    struct dnode *temp = dhead;
    int size = 0;                           // Hardik Kushwaha
    while(temp != NULL) {
        temp = temp->next;
        size++;
    }
    return size;                            // Returns the length(total elements) of the linked list
}
void displayMyDoublyList() {
    if(dhead == NULL) {                      // Checks whether linked list is empty or not
        printf("Linked List is Empty!\n");
        return;
    }                                           
    struct dnode *temp = dhead;
    printf("Linked List: ");
    while(temp != NULL) {                   // Prints the linked list
        printf("%d  ",temp->data);
        temp = temp->next;
    }                                       // Hardik Kushwaha
    printf("\n");
}

// 4. Circular Linked List
void MyCircularList() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|                Circular Linked List Implementation               |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Total Elements\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertAtPositionMyCircularList();
                break;
            case 2:
               deleteFromPositionMyCircularList();
                break;
            case 3:
                displayMyCircularList();
                break;
            case 4:
                printf("Total elements: %d\n",lengthMyCircularList());
                break;
            case 5:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);
}
void insertAtPositionMyCircularList() {
    struct cnode *newP=malloc(sizeof(struct cnode));
    printf("Enter the element: ");
    scanf("%d",&element);
    if(tail == NULL) {
        newP->data = element;
        newP->next = newP;
        tail = newP;
        printf("Element inserted successfully!\n");
        return;                                 // Hardik Kushwaha
    }

    do {
        printf("Enter the valid position: ");
        scanf("%d",&pos);
    } while(pos<=0 || pos>lengthMyCircularList()+1);
        
    if(pos == 1) {                               // Insertition at front(1st position)
        insertAtBeginingMyCircularList(element);
        return;
    }

    if(pos == lengthMyCircularList()+1) {        // Insertition at last(last position)
        insertAtLastMyCircularList(element);
        return;
    }

    struct cnode *temp = tail->next;              // Insertion at given position         
    int i=1;
    while(i<pos-1) {
        temp = temp->next;
        i++;
    }                                            // Hardik Kushwaha          
    newP->data = element;
    newP->next = temp->next;
    temp->next = newP;
    printf("Element inserted successfully!\n");
}
void insertAtBeginingMyCircularList(int element) {
    struct cnode *newP = malloc(sizeof(struct cnode));
    newP->data = element;
    newP->next = tail->next;                      // Hardik Kushwaha        
    tail->next = newP;
    printf("Element inserted successfully!\n");
}
void insertAtLastMyCircularList(int element) {
    struct cnode *newP = malloc(sizeof(struct cnode));
    newP->data = element;
    newP->next = tail->next;
                                            // Hardik Kushwaha
    tail->next = newP;
    tail = newP;
    printf("Element inserted successfully!\n");
}
void deleteFromPositionMyCircularList() {
    if(tail == NULL) {
        printf("Empty Linked List!\n");
        return;
    }
                                            //Hardik Kushwaha
    if(lengthMyCircularList() == 1) {
        printf("Element %d deleted successfully!\n",tail->data);
        tail = NULL;
        return;
    }

    do {
        printf("Enter the valid position: ");
        scanf("%d",&pos);
    } while(pos<=0 || pos>lengthMyCircularList());
        
    if(pos == 1) {                          // Deletion from front(1st position)
        deleteFromBeginingMyCircularList();
        return;
    }

    if(pos == lengthMyCircularList()) {     // Deletion from last(last position)
        deleteFromLastMyCircularList();
        return;
    }

    struct cnode *position = malloc(sizeof(struct cnode));
    struct cnode *temp = tail->next;
    int i=1;                                // Deletion from given position
    while(i<pos-1) {
        temp = temp->next;
        i++;
    }
    position = temp->next;                  // Hardik Kushwaha        
    temp->next = position->next;
    printf("Element %d deleted successfully!\n",position->data);
    free(position);
}
void deleteFromBeginingMyCircularList() {
    struct cnode *temp = tail->next;
    printf("Element %d deleted successfully!\n",temp->data);
    tail->next = temp->next;
    free(temp);                             // Hardik Kushwaha
}
void deleteFromLastMyCircularList() {
    struct cnode *temp = tail->next, *position=malloc(sizeof(struct cnode));
    int i = 1;
    while(i < lengthMyCircularList()-1) {
        temp = temp->next;
        i++;
    }                                       // Hardik Kushwaha
    position  = temp->next;
    temp->next = tail->next;
    tail = temp;
    printf("Element %d deleted successfully!\n", position->data);
    free(position);
}
int lengthMyCircularList() {
    if(tail == NULL) {
        printf("Linked List is Empty!\n");
        return 0;                           // Returns 0 if Linked list is empty
    }
    struct cnode *temp = tail->next;
    int size = 0;                           // Hardik Kushwaha
    do {
        temp = temp->next;
        size++;
    } while(temp != tail->next);
    return size;                            // Returns the length(total elements) of the Linked list
}
void displayMyCircularList() {
    if(tail == NULL) {                      // Checks whether Linked list is empty or not
        printf("Linked List is Empty!\n");
        return;
    }                                           
    struct cnode *temp = tail->next;
    printf("Linked List: ");                 // Prints the Linked list

    do {
        printf("%d  ",temp->data);
        temp = temp->next;
    } while(temp != tail->next);
    printf("\n");
}

// 5. Array implementation of Stack
void MyArrayStack() {
    int choice;
    do {
        printf("\n ------------------------------------------------------------------");
        printf("\n|                Array Implementation of Queue                     |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Top Element\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {                                                        // Hardik Kushwaha
            case 1:
                pushMyArrayStack();
                break;
            case 2:
                popMyArrayStack();
                break;
            case 3:
                displayMyArrayStack();
                break;
            case 4:
                topMyArrayStack();
                break;
            case 5:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);                                       // Hardik Kushwaha
}
void pushMyArrayStack() {
    if(top == StackMax-1) {
        printf("Stack OverFlow!\n");
        return;
    }
    int element;
    printf("Enter the element: ");
    scanf("%d",&element);
    stack[++top] = element;
    printf("Element pushed on the top of stack successfully!\n");
}                                                               // Hardik Kushwaha
void popMyArrayStack() {
    if(top == -1) {
        printf("Empty Stack!\n");
        return;
    }
    printf("Element %d poped successfully!\n", stack[top--]);
}                                                               // Hardik Kushwaha
void topMyArrayStack() {
    if(top == -1) {
        printf("Empty Stack!\n");
        return;
    }
    printf("Stack Top: %d\n", stack[top]);
}                                                               // Hardik Kushwaha
void displayMyArrayStack() {
    if(top == -1) {
        printf("Empty Stack!\n");
        return;
    }
    printf("Stack is:\n");
    for (int i=top; i>=0; i--)
        printf("|\t%d\t|\n", stack[i]);
    printf(" ---------------");
}                                                                // Hardik Kushwaha

// 6. Linked List Implementation of Stack
void MyListStack() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|              Linked List Implementation of Stack                 |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Top Element\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {                                                        // Hardik Kushwaha
            case 1:
                pushMyListStack();
                break;
            case 2:
                popMyListStack();
                break;
            case 3:
                displayMyListStack();
                break;
            case 4:
                topMyListStack();
                break;
            case 5:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);
}
void pushMyListStack() {
    if(lengthMyListStack == MaxStack) {
        printf("Stack OverFlow!\n");
        return;
    }
    int element;
    printf("Enter the element: ");
    scanf("%d",&element);
    struct snode *newP = malloc(sizeof(struct snode));
    newP->data = element;
    newP->link = shead;                                             // Hardik Kushwaha        
    shead = newP;
    printf("Element pushed on the top of stack successfully!\n");
    lengthMyListStack++;
}
void popMyListStack() {
    if(shead == NULL) {
        printf("Empty Stack!\n");
        return;
    }
    struct snode *temp = shead;
    printf("Element %d poped from the stack successfully!\n", temp->data);
    shead = shead->link;
    free(temp);
    lengthMyListStack--;
}
void displayMyListStack() {
    if(shead == NULL) {
        printf("Empty Stack!\n");
        return;
    }
    struct snode *temp = shead;
    printf("Stack is:\n");
    while(temp != NULL) {
        printf("|\t%d\t|\n", temp->data);
        temp = temp->link;
    }
    printf(" ---------------");
}
void topMyListStack() {
    if(shead == NULL) {
        printf("Empty Stack!\n");
        return;
    }
    printf("Stack Top: %d\n", shead->data);    
}

// 7. Array Implementation of Queue
void MyArrayQueue() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|                 Array Implementation of Queue                    |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {                                                        // Hardik Kushwaha
            case 1:
                enqueueMyArrayQueue();
                break;
            case 2:
                dequeueMyArrayQueue();
                break;
            case 3:
                displayMyArrayQueue();
                break;
            case 4:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 4);
}
void enqueueMyArrayQueue() {
    if(front == MaxQueue-1) {
        printf("Queue OverFlow!\n");
        return;
    }
    int element;
    printf("Enter the element: ");
    scanf("%d",&element);
    if(front == -1 && rear == -1) {
        front++;
        queue[++rear] = element;
        printf("Element inserted successfully!\n");
        return;
    }
    queue[++rear] = element;
    printf("Element inserted successfully!\n");
}
void dequeueMyArrayQueue() {
    if(front == -1) {
        printf("Empty Queue!\n");
        return;
    }
    if(front == rear) {
        printf("Deleted element is: %d\n", queue[front]);
        front = -1;
        rear = -1;
        return;
    }
    printf("Deleted element is: %d\n", queue[front++]);
}
void displayMyArrayQueue() {
    if(front == -1) {
        printf("Empty Queue!\n");
        return;
    }
    printf("Queue is: ");
    for(int i=front; i<=rear; i++) {
        printf("%d  ",queue[i]);
    }
    printf("\n");
}

// 8. Linked List Implementation of Queue
void MyListQueue() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|              Linked List Implementation of Queue                 |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {                                                        // Hardik Kushwaha
            case 1:
                enqueueMyListQueue();
                break;
            case 2:
                dequeueMyListQueue();
                break;
            case 3:
                displayMyListQueue();
                break;
            case 4:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 4);
}
void enqueueMyListQueue() {
    if(lengthMyListQueue == MaxQueue) {
        printf("Queue OverFlow!\n");
        return;
    }
    
    int element;
    printf("Enter the element: ");
    scanf("%d",&element);
    
    struct qnode *newP = malloc(sizeof(struct qnode));
    newP->data = element;                                      // Hardik Kushwaha        
    newP->link = NULL;
    
    if(listfront == NULL) {
        listrear = newP;
        listfront = newP;
        printf("Element inserted in the queue successfully!\n");
        lengthMyListQueue++;
        return;
    } 
    listrear->link = newP;
    listrear = newP;
    printf("Element inserted in the queue successfully!\n");
    lengthMyListQueue++;
}
void dequeueMyListQueue() {
    if(listfront == NULL) {
        printf("Empty Queue!\n");
        return;
    }

    struct qnode *temp = listfront;
    printf("Element %d deleted from the queue successfully!\n", temp->data);
    listfront = listfront->link;
    free(temp);
    lengthMyListQueue--;
}
void displayMyListQueue() {
    if(listfront == NULL) {
        printf("Empty Queue!\n");
        return;
    }

    struct qnode *temp = listfront;
    printf("Queue is: ");
    while(temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// 9. Array implementation of Doubly Ended Queue Deque
void MyArrayDeque() {
    int choice;
    do
    {
        printf("\n ------------------------------------------------------------------");
        printf("\n|       Array Implementation of Doubly Ended Queue (Deque)         |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1: Insertion at rear\n2: Insertion at front\n3: Deletion from front\n4: Deletion from rear\n5: Display\n6: Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueueAtRearMyArrayDeque();
                break;
            case 2:
                enqueueAtFrontMyArrayDeque();
                break;
            case 3:
                dequeueAtFrontMyArrayDeque();
                break;
            case 4:
                dequeueAtRearMyArrayDeque();
                break;
            case 5:
                displayMyArrayDeque();
                break;
            case 6:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 6);
}
void enqueueAtRearMyArrayDeque() {
    if(rear == MaxQueue-1) {
        printf("Queue OverFlow!\n");
        return;
    }
    
    printf("Enter the element: ");
    scanf("%d",&element);

    if(front == -1 && rear == -1) {
        front++;
        printf("Element inserted successfully at the end of Queue!\n");
        deque[++rear]=element;
        return;
    }
    deque[++rear]=element;
    printf("Element inserted successfully at the end of Queue!\n");
}
void dequeueAtFrontMyArrayDeque() {
    if(front == -1 && rear == -1) {
        printf("Empty Queue!\n");
        return;
    }
    if(front == rear) {
        printf("Deleted element is: %d\n",deque[front]);
        front = -1;
        rear = -1;
        return;
    }
    printf("Deleted element is: %d\n",deque[front++]);
}
void enqueueAtFrontMyArrayDeque() {
    if(rear == MaxQueue-1) {
        printf("Queue OverFlow!\n");
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &element);
    
    if(front == -1 && rear == -1) {
        rear++;
        deque[++front] = element;
        printf("Element inserted successfully at the front of Queue!\n");
        return;
    }

    for (int i = rear; i >= front; i--) {
        deque[i+1]=deque[i];
    }
    deque[front]=element;
    rear++;
    printf("Element inserted successfully at the front of Queue!\n");
}
void dequeueAtRearMyArrayDeque() {
    if(front == -1 && rear == -1) {
        printf("Empty Queue!\n");
        return;
    }
    printf("Deleted element is: %d\n",deque[rear--]);
    if(front == rear+1) {
        front = -1;
        rear = -1;
    }
}
void displayMyArrayDeque() {
    if(front == -1 && rear == -1) {
        printf("Empty Queue!\n");
        return;
    }
    printf("Deque is: ");
    for(int i = front; i <= rear;i++) {
        printf("%d ",deque[i]);
    }
    printf("\n");
}

// 10. Stack implementation of Queue
void MyStackQueue() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|                 Stack Implementation of Queue                    |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {                                                        // Hardik Kushwaha
            case 1:
                enqueueMyStackQueue();
                break;
            case 2:
                dequeueMyStackQueue();
                break;
            case 3:
                displayMyStackQueue();
                break;
            case 4:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 4);
}
void push1MyStackQueue(int element) {
    stack1[++top1] = element;
}
void push2MyStackQueue(int element) {
    stack2[++top2] = element;
}
int pop1MyStackQueue() {
    return stack1[top1--];
}
int pop2MyStackQueue() {
    return stack2[top2--];
}
void enqueueMyStackQueue() {
    if(top1 == MaxQueue-1) {
        printf("Queue OverFlow!\n");
        return;
    }

    int element;
    printf("Enter the element: ");
    scanf("%d",&element);
    push1MyStackQueue(element);
    lengthMyStackQueue++;
    printf("Element inserted successfully!\n");
}
void dequeueMyStackQueue() {
    if(top1 == -1 && top2 == -1) {
        printf("Empty Queue!\n");
        return;
    }
    for(int i=0; i<lengthMyStackQueue; i++) {
        push2MyStackQueue(pop1MyStackQueue());
    }
    printf("Deleted Element is: %d\n",pop2MyStackQueue());
    lengthMyStackQueue--;
    for(int i=0; i<lengthMyStackQueue; i++) {
        push1MyStackQueue(pop2MyStackQueue());
    }
}
void displayMyStackQueue() {
    if(lengthMyStackQueue == 0) {
        printf("Empty Queue!\n");
        return;
    }
    printf("Queue is: ");
    for(int i=0; i<lengthMyStackQueue; i++) {
        printf("%d  ",stack1[i]);
    }
    printf("\n");
}

// 11. Array implementation of BST
void MyArrayBST() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|          Array Implementation of Binary Search Tree              |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Insert\n2. Display\n3. Searching\n4. Total Nodes\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {                                                        // Hardik Kushwaha
            case 1:
                insertMyArrayBST();
                break;
            case 2:
                displayMyArrayBST();
                break;
            case 3:
                searchingMyArrayBST();
                break;
            case 4:
                if (totalNodesMyArrayBST == 0) {
                    printf("Empty BST!\n");
                } else {
                    printf("Total Nodes in BST: %d\n",totalNodesMyArrayBST);
                }
                break;
            case 5:
                printf("Exited successfully!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);
}
void insertMyArrayBST() {
    int element, i = rootArray;
    printf("Enter the element: ");
    scanf("%d", &element);
    while (element <= 0) {
        printf("Enter the valid element (element must be greater than zero): ");
        scanf("%d", &element);
    }
    totalNodesMyArrayBST++;
    
    if(bst[rootArray] == 0) {                                            // Hardik Kushwaha
        bst[rootArray] = element;
        printf("Root inserted successfully!\n");
        return;
    }
    while(i < MaxBST) {
        if (element <= bst[i]) {
            if(bst[2*i] == 0) {
                bst[2*i] = element;
                printf("Node inserted successfully!\n");
                break;                                              // Hardik Kushwaha
            } else {
                i = 2*i;
            }
        } else {
            if(bst[2*i+1] == 0) {
                bst[2*i+1] = element;
                printf("Node inserted successfully!\n");
                break;
            } else {                                                // Hardik Kushwaha
                i= 2*i+1;
            }
        }
    }
}
void displayMyArrayBST() {
    if(bst[rootArray] == 0) {
        printf("Empty Binary Search Tree!\n");
        return; 
    }
    int choice;
    printf("\nTree Traversal\n1. Inorder Traversal\n2. Preorder Traversal\n3. Postorder Traversal\nEnter the choice: ");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("Inorder Traversal of BST is: ");
            inorderTraversalMyArrayBST(rootArray);   
            printf("\n");
            break;
        case 2:
            printf("Preorder Traversal of BST is: ");
            preorderTraversalMyArrayBST(rootArray);   
            printf("\n");
            break;
        case 3:
            printf("Postorder Traversal of BST is: ");
            postorderTraversalMyArrayBST(rootArray);
            printf("\n");
            break;
        default:
            printf("Invalid Choice!\n");
            break;
    }
}
void inorderTraversalMyArrayBST(int i) {
    if (bst[i] == '\0') {
        return;
    } else {
        inorderTraversalMyArrayBST(2*i);
        printf("%d ",bst[i]);
        inorderTraversalMyArrayBST(2*i+1);
    }
}
void preorderTraversalMyArrayBST(int i) {
    if (bst[i] == '\0') {
        return;
    } else {
        printf("%d ",bst[i]);
        preorderTraversalMyArrayBST(2*i);
        preorderTraversalMyArrayBST(2*i+1);
    }
}
void postorderTraversalMyArrayBST(int i) {
    if (bst[i] == '\0') {
        return;
    } else {
        postorderTraversalMyArrayBST(2*i);
        postorderTraversalMyArrayBST(2*i+1);
        printf("%d ",bst[i]);
    }
}
void searchingMyArrayBST() {
    if (totalNodesMyArrayBST == 0) {
        printf("Empty BST!\n");
        return;
    }
    int element, state = 0, i = rootArray;
    printf("Enter the element: ");
    scanf("%d", &element);
    while (bst[i] != '\0') {
        if (element <= bst[i]) {
            if (element == bst[i]) {
                state = 1;
                break;
            }
            else {
                i = 2*i;
            }
        } else {
            i = 2*i + 1;
        }
    }
    if (state == 0) {
        printf("Node not found in BST!\n");
    } else {
        printf("Node present in the BST!\n");
    }
}

// 12. Linked List implementation of BST
void MyListBST() {
    int choice;
    do{
        printf("\n ------------------------------------------------------------------");
        printf("\n|               Linked List Implementation of BST                  |");
        printf("\n ------------------------------------------------------------------");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Searching\n5. Total Nodes\n6. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice) {                                                        
            case 1:
                insertMyListBST();
                break;
            case 2:
                deleteMyListBST();
                break;
            case 3:
                displayMyListBST();
                break;
            case 4:
                searchingMyListBST();
                break;
            case 5:
                if (root == NULL) {
                    printf("Empty BST!\n");
                } else {
                    printf("Total Nodes in BST: %d\n", totalNodesMyListBST);
                }
                break;
            case 6:
                printf("Exited successfully!\n");
                // printf("Developed By: Hardik Kushwaha")
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 6);
}                                                                 // Hardik Kushwaha
void insertMyListBST() {
    int element;
    printf("Enter the element: ");
    scanf("%d",&element);
    struct bstNode *newP = malloc(sizeof(struct bstNode));
    newP->data = element;
    newP->left = NULL;
    newP->right = NULL;
    totalNodesMyListBST++;

    if(root == NULL) {
        root = newP;
        printf("Root inserted successfully!\n");
        return;
    }

    struct bstNode *temp = root;
    while(temp != NULL) {
        if(element <= temp->data) {
            if(temp->left == NULL) {
                temp->left = newP;
                printf("Node inserted successfully!\n");
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if(temp->right == NULL) {
                temp->right = newP;
                printf("Node inserted successfully!\n");
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}
void deleteMyListBST() {
    if(root == NULL) {
        printf("Empty BST!\n");
        return;
    }
    int element, state = 0, max = 0, min;
    totalNodesMyListBST--;
    // printf("Developed By: Hardik Kushwaha")
    if (root->left == NULL && root->right == NULL) {            // if only root is present
        printf("Root %d deleted successfully!\n", root->data);
        root = NULL;
        return;
    }
    printf("Enter the element: ");
    scanf("%d", &element);
    struct bstNode *prevNode, *temp = root, *minNode, *maxNode;

    while (temp != NULL) {
        if (element <= temp->data) {
            if(element == temp->data) {
                state = 1;

                if (temp->left == NULL && temp->right == NULL) {// if element node is leaf
                    if (prevNode->left == temp) {
                        printf("Node %d deleted successfully!\n", temp->data);
                        prevNode->left = NULL;
                        free(temp);
                        break;
                    } else {
                        printf("Node %d deleted successfully!\n", temp->data);
                        prevNode->right = NULL;
                        free(temp);
                        break;
                    }
                } else if (temp->left == NULL || (temp->left != NULL && temp->right != NULL)) {     // if left sub-tree is not present or both sub-tree is present 
                    minNode = temp->right;
                    min = minNode->data;
                    prevNode = temp;
                    while (minNode != NULL) {           // if left sub-tree of temp->right is present
                        if (min > minNode->data) {
                            min = minNode->data;
                        }
                        if (minNode->left == NULL && minNode->right == NULL) {
                            break;
                        }
                        if (minNode->left == NULL) {
                            break;
                        }
                        prevNode = minNode;
                        minNode = minNode->left;
                    }// printf("Developed By: Hardik Kushwaha")
                    printf("Node %d deleted successfully!\n", temp->data);
                    temp->data = min;
                    if (minNode == temp->right) {           // left sub-tree of temp->right is not present
                        if (minNode->right == NULL && minNode->left == NULL) {  // right sub-tree of temp->right is also not present
                            prevNode->right = NULL;
                            free(minNode);
                            break;
                        } else if (minNode->right != NULL) {    // right sub-tree of temp->right is present
                            prevNode->right = minNode->right;
                            free(minNode);
                            break;
                        } 
                    } else {
                        if (minNode->left == NULL && minNode->right == NULL) {
                            prevNode->left = NULL;
                            free(minNode);
                        } else {
                            prevNode->left = minNode->right;
                            free(minNode);
                        }
                        break;
                    }
                } else if (temp->right == NULL) {       // right sub-tree is not present
                    maxNode = temp->left;
                    max = maxNode->data;
                    prevNode = temp;
                    while (maxNode != NULL) {
                        if (max < maxNode->data) {
                                max = maxNode->data;
                            }
                            if (maxNode->left == NULL && maxNode->right == NULL) {
                                break;
                            }
                            if (maxNode->right == NULL) {
                                break;
                            }
                            prevNode = maxNode;
                            maxNode = maxNode->right;
                    }
                    printf("Node %d deleted successfully!\n", temp->data);
                    temp->data = max;
                    if (maxNode == temp->left) {           // right sub-tree of temp->left is not present
                        if (maxNode->right == NULL && maxNode->left == NULL) {  // left sub-tree of temp->left is also not present
                            prevNode->left = NULL;
                            free(maxNode);
                            break;
                        } else if (maxNode->left != NULL) {    // left sub-tree of temp->left is present
                            prevNode->left = maxNode->left;
                            free(maxNode);
                            break;
                        } 
                    } else {
                        if (maxNode->left == NULL && maxNode->right == NULL) {
                            prevNode->right = NULL;
                            free(maxNode);
                        } else {
                            prevNode->right = maxNode->left;
                            free(maxNode);
                        }
                        break;
                    }
                }// printf("Developed By: Hardik Kushwaha")
            } else {
                prevNode = temp;
                temp = temp->left;
            }
        } else {
            prevNode = temp;
            temp = temp->right;
        }
    }
    if (state == 0) {
        printf("Node not present in the Tree!\n");
    }
}
void displayMyListBST() {
    if(root == NULL) {
        printf("Empty Binary Search Tree!\n");
        return; 
    }
    struct bstNode *temp = root;
    // printf("Developed By: Hardik Kushwaha")
    int choice;
    printf("\nTree Traversal\n1. Inorder Traversal\n2. Preorder Traversal\n3. Postorder Traversal\nEnter the choice: ");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("Inorder Traversal of BST is: ");
            inorderTraversalMyListBST(temp);   
            printf("\n");
            break;
        case 2:
            printf("Preorder Traversal of BST is: ");
            preorderTraversalMyListBST(temp);   
            printf("\n");
            break;
        case 3:
            printf("Postorder Traversal of BST is: ");
            postorderTraversalMyListBST(temp);
            printf("\n");
            break;
        default:
            printf("Invalid Choice!\n");
            break;
    }
}
void preorderTraversalMyListBST(struct bstNode *temp) {
    if(temp == NULL)
        return;
    printf("%d ", temp->data);
    preorderTraversalMyListBST(temp->left);
    preorderTraversalMyListBST(temp->right);
}
void inorderTraversalMyListBST(struct bstNode *temp) {
    if(temp == NULL)
        return;
    inorderTraversalMyListBST(temp->left);
    printf("%d ", temp->data);
    inorderTraversalMyListBST(temp->right);
}
void postorderTraversalMyListBST(struct bstNode *temp) {
    if(temp == NULL)
        return;
    postorderTraversalMyListBST(temp->left);
    postorderTraversalMyListBST(temp->right);
    printf("%d ", temp->data);
}
void searchingMyListBST() {
    if(root == NULL) {
        printf("Empty BST!\n");
        return;
    }
    int element, state = 0;
    printf("Enter the element: ");
    scanf("%d", &element);
    struct bstNode *temp = root;

    while (temp != NULL) {
        if (element <= temp->data) {
            if(element == temp->data) {
                state = 1;
                break;
            } else {
                temp = temp->left;
            }
        } else {
            temp = temp->right;
        }
    }
    // printf("Developed By: Hardik Kushwaha")
    if (state == 1) {
        printf("Element is Present!\n");
    } else {
        printf("Element not Found!\n");
    }
}
