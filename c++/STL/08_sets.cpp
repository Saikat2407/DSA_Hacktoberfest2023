// Sets are containers like maps...but sets store keys, not their values.
// Sets (ordered sets) store and print "unique" keys/elements "in sorted/lexicographical order".
// For maps & sets, it is better to print them using range-based loops using iterators.
// Vectors can be printed using v[i] in for-loop OR using range-based loops using iterators.

#include <bits/stdc++.h>
using namespace std;

void print(set<string> &s)
{ // s passed by reference
    for (string value : s)
        cout << value << endl;
}

int main()
{

    /*(1)
    set<string> s;
    s.insert("abc");  // O(log n)
    s.insert("pqr");
    s.insert("abc");  // to insert in maps, we can use m[4] = "abc" OR m.insert({4,"abc"}) as we are inserting a key-value pair.
    s.insert("xyz");  // in sets, we can use only s.insert("abc") as sets do not have values...they store only keys.

    // Printing set using: (i) for-loop using iterators
    set<string> :: iterator it;   // no need to declare 'iterator it' if 'auto' used.
    for(it=s.begin(); it!=s.end(); it++){
        cout<< (*it) <<endl;
    }

    // Printing set using: (ii) range-based loop using iterators
    for(auto value : s){
        cout<< value << endl;
    }

    // Printing set using: (iii) range-based loop
    for(string value : s ){
        cout << value <<endl;
    }

    // (iv)
    print(s);
    */

    /*(2)
    set<string> s;
    s.insert("abc");
    s.insert("pqr");
    s.insert("abc");
    s.insert("xyz");
    s.insert("pqr");

    auto it = s.find("abc");  // s.find() returns iterator pointing to that element if present, else returns s.end() if element is absent.
    if(it != s.end()){        // hence, store s.find() in iterator (auto it) and use *it to print value of that element.
        cout<< (*it);
    }
    cout<<endl<<endl;

    it = s.find("pqr");   // it declared already, hence don't use auto keyword
    if(it != s.end()){
        s.erase(it);      // s.erase() can take element as input OR its iterator (if s.find() is stored in iterator it)
    }

    // s.erase("abc");   // O(log n)
    print(s);
    */

    /*(3)    // Given N strings, print unique strings in lexicographical order.
    set<string> s;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        s.insert(str);
    }
    cout<<endl;
    for(auto value : s){
        cout<< value << endl;    // ordered sets will print only unique strings and that too in sorted/lexicpgraphical order.
    }
    */

    return 0;
}