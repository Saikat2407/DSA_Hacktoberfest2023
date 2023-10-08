#include <bits/stdc++.h>
using namespace std;

int main(){

    stack<int> s;   // LIFO
    s.push(2);
    s.push(7);
    s.push(4);
    s.push(9);
    while(!s.empty()) {  // s.empty() is a boolean...will return 1 if stack is empty, else 0
        cout<< s.top() << endl;   // s.top() returns topmost element in the stack
        s.pop();                  // s.pop() removes topmost element in the stack
    }


    queue<string> q;   // FIFO
    q.push("pqr");
    q.push("abc");
    q.push("xyz");
    q.push("lmn");
    while(!q.empty()) {  // q.empty() is a boolean...will return 1 if queue is empty, else 0
        cout<< q.front() << endl;     // q.top() returns the front element in the queue
        q.pop();                      // q.pop() removes the front element in the queue
    }

    return 0;
}