// Maps are the associative containers that store sorted key-value pair, in which each key is unique and it can be inserted or deleted but cannot be altered.
// Values associated with keys can be changed.
// Maps (sorted/ordered maps) store keys in sorted order in case of integers and lexicographically sorted order in case of strings.
// Insertion in ordered maps takes place through red-black trees and in unordered maps through hashing.

#include <bits/stdc++.h>
using namespace std;

int main()
{

    /*(1)
    // map<int,string> m = {{9,"abc"}, {4,"xyz"},{7,"pqr"}};
    map<int,string> m;
    m[9] = "abc";  // insertion in ordered map takes O(logn)
    m[4] = "xyz";
    m.insert({7,"pqr"});  //OR m.insert(make_pair(7,"pqr"));


    map<int,string> :: iterator it;   // no need to declare 'iterator it' if 'auto' used.
    for(it=m.begin(); it!=m.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    for(auto &pr : m){  // takes O(nlogn) i.e logn for accessing pair of each map.
        cout<<pr.first<<" "<<pr.second<<endl;   // Here, pr represents value of iterator pointing to pair in the map.
    }                                           // hence, no need to use * operator...i.e (*pr).first
    */

    /*(2)
    map<int,string> m;
    m[9] = "abc";  // insertion in ordered map takes O(logn)
    m[4] = "xyz";              // But if map<string,string> m;
    m[7] = "pqr";              // m["abc"] = "pqr";  --> takes s.size()*logn
    m[2] = "lmn";

    auto it = m.find(4);    // O(logn)  // m.find() returns an iterator. Hence, store it in 'auto it'.  // no need to declare 'iterator it' if 'auto' used.
    if(it==m.end())
        cout<< "Mapped value of key 4 not found!";
    else
        cout<<(*it).first<<" "<<(*it).second<<endl<<endl;

    m.erase(7);  // O(logn)  // m.erase() possible only when it != m.end()     // or else -> auto it = m.find(4),then m.erase(it)
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<endl;   // Here, pr represents 'iterator' pointing to pair in the map.
    }

    // if(m[4]=="xyz"){
    //     cout<<"Mapped value of key 4 found";
    // }

    m.clear();
    */

    /*(3)
    map<int,int > m;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        m[x] = y;
    }

    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    */

    /*(4)    // Given N strings, print unique strings in lexicographical order with their frequency.
    int n;
    cin>>n;
    map<string,int> m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        // m[s] = m[s] + 1;   // m[s] is 0 initially for any key. Keys should be unique but mapped values can be same.
        m[s]++;
    }
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    */

    /*(5)  // Striver
    map<int, int> m;
    m.insert({4,16});
    m[3] = 9;
    m[9] = 81;
    m.insert({5,25});

    for(auto it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }

    for(auto it = m.begin(); it!=m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
        // cout<<*it.first<<" "<<*it.second<<endl;   // throws error as it tries to access *(it.first)
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    auto it = m.find(4);
    cout<<(*it).second<<endl;   // 16


    // cout<<*(it+1).second<<end;  // gives error as maps and sets do not store elements in contiguous memory locations
    advance(it, 2); // Now the iterator is 2 position ahead of where you want it to be.
    cout<<(*it).second<<endl; // 81


    auto it2 = m.find(6);
    cout<<it2->second<<endl;   // 0 as there is no key 6
    */

    return 0;
}
