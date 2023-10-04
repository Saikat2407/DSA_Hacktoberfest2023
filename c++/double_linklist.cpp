#include <iostream>
using namespace std;

class Node
{ // Creating a node
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class Dlinklist // class of double linklist
{
private:
    Node *head;

public:
    Dlinklist()
    {
        head = NULL;
    };
    void in_Beg(int value);          // Insert a node at begining
    void display();                  // Display a Linklist
    int count();                     // Counting the noumber of element
    void in_Any(int value, int pos); // Insert at any position
    void del_Beg();                  // Deleting a node at begining
    void del_any(int pos);           // Deleting at any position
    void rev_display();              // For reverse display
};

int Dlinklist ::count()
{ // Count Function
    int c = 0;
    if (head == NULL)
    {
        return c;
    }
    else
    {
        c++;
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
            c++;
        }
        return c;
    }
}

void Dlinklist ::in_Beg(int value)
{ // Insert Begining Function
    if (head == NULL)
    {
        Node *temp = new Node(value);
        head = temp;
        cout << "inserted 1" << endl;
        return;
    }
    else
    {
        Node *temp = new Node(value);
        head->prev = temp;
        temp->next = head;
        head = temp;
        cout << "inserted" << endl;
        return;
    }
}

void Dlinklist ::display() // Display Function
{
    cout << "The items are" << endl;
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << "\t";
        current = current->next;
    }
}

void Dlinklist ::in_Any(int value, int pos)
{ // Insert at any position Function
    if (pos < 0 || pos > count())
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        if (pos == 0)
        {
            in_Beg(value);
        }
        else
        {
            Node *temp = new Node(value);
            Node *p = head;
            for (int i = 0; i < pos - 1; i++)
            {
                p = p->next;
            }
            temp->prev = p->prev;
            p->prev->next = temp;
            temp->next = p;
            p->prev = temp;
        }
    }
    cout << "inserted" << endl;
}

void Dlinklist ::del_Beg()
{ // Delete Begining Function
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
}

void Dlinklist ::del_any(int pos)
{ // Delete at any position Function
    if (pos < 1 || pos > count())
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        if (pos == 1)
        {
            del_Beg();
        }
        else
        {
            Node *p = head;
            for (int i = 0; i < pos - 1; i++)
            {
                p = p->next;
            }
            Node *temp = p;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete temp;
        }
    }
}

void Dlinklist::rev_display()
{ // Reverse display function
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->prev;
    }
}

int main()
{ // Main Function
    Dlinklist p;
    p.in_Beg(4);
    p.in_Beg(2);
    p.in_Beg(1);
    p.display();
    cout << endl;
    p.in_Any(3, 3);
    p.display();
    cout << endl;
    p.del_any(3);
    p.display();
    cout << endl;
    p.rev_display();

    return 0;
}