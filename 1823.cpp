#include <iostream>
using namespace std;
class Stack
{
    int top;

public:
    Stack(){
        top = -1;
    }

    bool isemp(){
        return top == -1;
    }

    bool isfull(int n){
        return top == n - 1;
    }

    void push(int arr[], int n, int data){
        if (top == n - 1)
        {
            cout << "STACK OVERFLOW\n";
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop(int arr[], int n){
        if (top == -1)
        {
            cout << "STACK IS EMPTY\n";
            return 0;
        }
        top--;
        return arr[top + 1];
    }

    void display(int arr[]){
        if (top == -1)
        {
            cout << "STACK UNDERFLOW\n";
            return;
        }
        cout << "Elements in the stack\n";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << '\n';
        }
    }
};

int main()
{
    int ch, data,n;
    cout<<"Enter the size of the stack\n";
    cin >> n;
    int arr[n];

    Stack st;
    while (1)
    {
        cout << "\nEnter your choice\t  1 for push\t  2 for pop\t 3 for display \t  4 to check if stack is empty \t  5 to check if stack is full\n";
        cin >> ch;
        if (ch == 1){
            cout << "Enter the value" << endl;
            cin >> data;
            st.push(arr, n, data);
        }
        else if (ch == 2){
            cout << "element removed:" << st.pop(arr, n) << endl;
        }
        else if (ch == 3){
            st.display(arr);
        }
        else if (ch == 4){
            if (st.isemp())
                cout << "Stack is empty\n";
            else
                cout << "stack is not empty\n";
        }
         else if (ch == 5){
            if (st.isfull(n))
                cout << "Stack is full\n";
            else
                cout << "stack is not full\n";
        }
        else{
            break;
        }
    }
}


