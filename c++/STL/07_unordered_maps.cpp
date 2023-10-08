// Time complexity:-  Ordered maps -> O(logn)  and Unordered maps -> O(1) for most operations.
// Inbuilt implementation:-  Ordered maps -> Red-black trees (insertion on basis of comparision) and Unordered maps -> Hashing   (insertion on basis of hash value).
// Valid key datatypes:-  Complex data types cannot be stored in unordered_maps. For ex: unordered_map<pair<int,int>, string>  m. This is because pairs do not have inbuilt hash table. But this can be done using ordered maps.


#include <bits/stdc++.h>
using namespace std;

int main(){
    /*(1)
    unordered_map<int,string> m;
    m[9] = "abc";  // insertion in unordered maps takes O(1)
    m[4] = "xyz";                  
    m[7] = "pqr";                    
    m[2] = "lmn";
    
    auto it = m.find(4);    // O(1)  // m.find() returns an iterator. Hence, store it in 'auto it'.  // no need to declare 'iterator it' if 'auto' used.
    if(it==m.end())
        cout<< "Mapped value of key 4 not found!";
    else
        cout<<(*it).first<<" "<<(*it).second<<endl<<endl;

    m.erase(7);  // O(l1)  // m.erase() possible only when it != m.end()
    for(auto &pr : m){   
        cout<<pr.first<<" "<<pr.second<<endl;   // Here, pr represents value of iterator pointing to pair in the map.
    }                                           // hence, no need to use * operator...i.e (*pr).first
    
    m.clear();
    */
    
    /*(2)    // Given N strings and Q queries. In each query you are given a string. Print frequency of that string.
    int n;
    cin>>n;
    map<string,int> m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        // m[s] = m[s] + 1;   // m[s] is 0 initially for any key. Keys should be unique but mapped values can be same.
        m[s]++;
    }
    
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>> s;
        cout<< m[s]<<endl;
    }
    */
    
    return 0;
}