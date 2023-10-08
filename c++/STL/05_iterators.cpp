// Iterators are pointers to containers
// (it+1) points to next location in memory and it++ points to next iterator...(no difference in case of vectors since they have contiguous memory location, but different for maps,sets,etc)
// Vector of integers/pairs...can be printed through (i) for-loop (ii)range-based loop (iii)iterators.
// Best way to iterate through a container is using auto keyword + range-based loops combined.

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    /*(1)
    vector<int> v = {3, 4, 5, 7, 8};  //vector of integers...can be printed through (i) for-loop (ii)range-based loop (iii)iterators.
    for(int i=0; i<v.size(); i++){
    cout<<v[i]<<" ";
    }
    cout<<endl;

    vector<int> :: iterator it = v.begin();
    cout<< *(it) <<endl;
    cout<< *(it+1) <<endl;
    cout<< *(it+2) <<endl<<endl;

    for(it = v.begin(); it != v.end(); it++){
        cout<< *it<< " ";
    }
    cout<<endl;

    for(int &value : v){     // Range-based loops  (copy of integers in vector v is paased to value. Hence, use &value to change actual vector v.)
        value++;
        cout<< value <<" ";
    }
    cout<<endl;
    for(int value : v){     
      cout<< value <<" ";
    }
    */


    /*(2)
    vector<pair<int,int> > v = {{3,4},{7,9},{12,16}};  //vector of pairs
    
    vector<pair<int,int> > :: iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout<< (*it).first<<" "<<(*it).second<<endl;  // (*it).first <=> (it->first) and (*it).second <=> (it->seconṇṇṇd)
    }

    for(pair<int,int> value : v){     // Range-based loops
        cout<< value.first <<" "<< value.second<<endl;
    }
    cout<<endl;
    */

    
    /*(3)   [better version of (2)]
    auto a = 5.5;
    cout<< a <<" "<<typeid(a).name()<<endl;
    
    vector<pair<int,int> > v = {{3,4},{7,9},{12,16}};  //vector of pairs
    
    // vector<pair<int,int> > :: iterator it;  --> no need to declare in this syntax
    
    // for(auto it = v.begin(); it != v.end(); it++){
    //     cout<< (*it).first<<" "<<(*it).second<<endl; 
    // }
    
    for(auto value : v){     // Range-based loops   (auto detects that value is an pair<int,int>)
        cout<< value.first <<" "<< value.second<<endl;
    }
    */

    return 0;
}


/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector of pairs
    vector<pair<int,int> > v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    
    // for(int i=0; i<n; i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    
    for(auto &pr : v){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    return 0;
}
*/