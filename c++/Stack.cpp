#include <iostream>
#include <list>
using namespace std;

class Stack
{
public:
    int data;
    list<int>st;
    Stack()
    {
        
    }
    int push(int data)
    {
        this->data = data;
        st.push_back(data);
        return data;
    }
    bool isEmpty()
    {
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int peek()
    {
        return st.back();
    }
    int pop()
    {
        int element = st.back();
        st.pop_back();
        return element;
    }
    int size()
    {
        return st.size();
    }
};

int main()
{
    Stack s;
    cout << "Is empty " << s.isEmpty() << endl; 
    s.push(4);
    cout << "First Element " << s.peek() << endl;
    cout << "Is empty " << s.isEmpty() << endl;
}
