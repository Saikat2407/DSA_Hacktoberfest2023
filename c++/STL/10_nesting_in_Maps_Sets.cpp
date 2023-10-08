// complex containers cannot be stored in unordered_maps or unordered_sets.

#include <bits/stdc++.h>
using namespace std;

int main(){

    /*(1)
    map<pair<int,int>, int> m1;  // These pairs are stored in sorted order in the map.
    pair<int,int> p1,p2;                    // or  pair<int,int> p1 ={3,5};
    p1 = {3,5};
    p2 = {3,4};
    cout << (p1>p2) <<endl;  // compares 1st integer of both pairs and then the 2nd integer.  
    
    map<set<int>, int> m2;    // These sets are stored in sorted order in the map.
    set<int> s1 = {5,3,6,8};
    set<int> s2 = {5,3,7};
    cout << (s1<s2) <<endl;  // compares 1st integer of both sets and then the 2nd integer and so on. 
    */

    
    
//---------------------------------------------------------------------------------------------------------------------
    
    //input:-                output:-
    //  2                      pqr lmn       // pqr > xyz in lexicographical order
    //  xyz abc 4              3
    //  9 7 8 5                1 0 8
    //  pqr lmn 3              xyz abc
    //  1 0 8                  4  
    //                         9 8 7 5    
    
    /*(2)
    map<pair<string,string>, vector<int> > m;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string fn, ln;   // first name and last name
        int ct; 
        cin>> fn >> ln >>ct;         // count of integers in the vector
        for(int i=0; i<ct; i++){
            int x;
            cin >> x;
            m[{fn,ln}].push_back(x);   // here m[] will store/represent a vector as it stores a vector. Hence .push_back can be used. 
        }
    }
    for(auto &it : m){    // it.first stores the pair and it.second stores the vector  
        cout<< it.first.first << " "<< it.first.second<<endl;  // fn = it.first.first and ln = it.first.second
        cout<< it.second.size() <<endl;
        for(auto &num : it.second){
            cout<< num<<" ";
        }
        cout<<endl;
    }
    */  
    

// Another Way:-
    
    // for(int i=0; i<n; i++){   
    //     string fn, ln;  
    //     int ct; 
    //     cin>> fn >> ln >>ct;  
    //     vector<int> v;
    //     for(int i=0; i<ct; i++){
    //         int x;
    //         cin >> x;
    //         v.push_back(x);
    //     }
    //     m[{fn,ln}]=v; 
              
    // }
    

//------------------------------------------------------------------------------------------------------------------
    
    
    // input:- 
    // 3
    // Eve 78
    // Bob 99
    // Alice 78
    
    // The Monk and Class Marks //m.rbegin()
    int n;
    cin>>n;
    map<int,multiset<string> > m;
    while(n--){
        int marks;
        string name;
        cin>> name >> marks;
        m[marks].insert(name);   // m[] stores/represents a set ...hence use .insert() operator.
    }

    auto it = --m.end();   
    while(true){     
        auto &students = (*it).second; 
        int marks = (*it).first;
        for(auto &student : students){   
            cout<< student <<" "<<marks<<endl; 
        }
        if(it == m.begin()) break;     
        it--;   
    }

    return 0;
}