// Ordered sets / Sets store and print "unique" keys/elements "in sorted/lexicographical order".    // O(log n)
// Unorderd sets store and print "unique" keys/elements "in unsorted order".                 // O(1)
// Multisets store and print all (including duplicates) keys/elements "in sorted/lexicographical order".   //O(log n)
// Multisets (ordered + duplicates allowed) are better to use than 'Priority Queues' in stl.

// set<string> s : ordered  + unique
// unordered_set<string> s: unordered + unique
// muliset<srring> s : ordered + duplicates
// only array, vector, and string can store elements in contiguous memory locations, not maps and sets

#include <bits/stdc++.h>
#define ll long long // range of integers is  till 10^9
using namespace std;

void print(multiset<string> &s)
{ // s passed by reference
    for (string value : s)
        cout << value << endl;
}

int main()
{

    /*(1)   // Given N strings and Q queries. In each query you are given a string. Print yes if string is present, else print no.
    unordered_set<string> s;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        s.insert(str);    // O(1)
    }

    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        if(s.find(str)==s.end())
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    */

    /*(2)
    multiset<string> s;
    s.insert("abc");   // O(log n)
    s.insert("pqr");
    s.insert("abc");
    s.insert("xyz");
    s.insert("pqr");

    for(auto value : s){
        cout<< value << endl;  // will print all strings in lexicographical/sorted order including repeating strings
    }

    print(s);     // will print all strings in lexicographical/sorted order including repeating strings
    */

    /*(3)
    multiset<string> s;
    s.insert("abc");
    s.insert("pqr");
    s.insert("abc");
    s.insert("xyz");
    s.insert("pqr");

    auto it = s.find("pqr");   // in multisets, s.find() returns the iterator of the first element in the set if that element is repeating.
    if(it != s.end()){
        cout<< (*it) <<endl<<endl;
        s.erase(it);  // in multisets, if s.erase(it) is used....i.e iterator of element is passed in s.erase(), then only that element is deleted even if it is repeating.
    }
    //s.erase("abc");  // in multisets, if s.erase("abc") is used...then all the "abc" elements are deleted in the multiset.
    print(s);
    */

    /*(4)    // Monk and the magical candy bags [HackerEarth]
    int t;
    cin>>t;
    while(t--){     // for(int i=0; i<t; i++);
        int n,k;
        cin >> n >> k;
        multiset<ll> bags;
        for(int i=0; i<n; i++){
            ll candy_ct;
            cin >> candy_ct;
            bags.insert(candy_ct);   // candies will be stored in sorted (ascending order)
        }

        ll total_candies = 0;
        for(int i=0; i<k; i++){               // last_it points to the the iterator next to the last iterator
            auto last_it = (--bags.end());    // OR auto last_it = bags.end();  last_it--;
            ll candy_ct = *last_it;   // but (bags.end()--) gives wrong output as it will first assign next to last iterator to last_it and then decrement it.
            total_candies+=candy_ct;
            bags.erase(last_it);
            bags.insert(candy_ct / 2);
        }
        cout<< total_candies <<endl;
    }
    */

    return 0;
}