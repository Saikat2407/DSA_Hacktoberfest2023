#include <bits/stdc++.h>
using namespace std;


int main(){
    string arr[3]={"Harry", "Shubham", "Lovish"};
    string* p = arr;
    cout<<*p<<endl;
    cout<<*(p+1)<<endl;
    cout<<*(p+2)<<endl;
    
    string name = "Harry";
    cout<<name.length()<<endl;
    cout<<name.size()<<endl;
    cout<<name.at(1)<<endl;
    
    return 0;
}