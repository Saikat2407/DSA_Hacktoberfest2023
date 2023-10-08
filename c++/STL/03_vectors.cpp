 // Vectors are like arrays whose size can change dynamically.
 // In CP, for locally declared vectors, max size = 10^5 and for globally declared vectors, max size = 10^7.
    
#include <bits/stdc++.h>
using namespace std;

void printVect(vector<int> v){
    cout<< "Size: "<<v.size()<<endl;
    cout<<"Given vector is "<<endl; 
    for(int i=0; i<v.size(); i++){
       cout<< v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    /*(1)
    vector<int> v = {4, 5, 6};   // vector of integers  (vector<int> v(3) = {4, 5, 6}; will give error, declare as vector<int> v = {4, 5, 6};  )
    printVect(v);
    v.push_back(7);   // push_back() and pop_back() are done in O(1) time complexity
    v.push_back(8);   
    v.pop_back();
    printVect(v);
    
    cout<<endl;
    vector<int> v2 = v;  // copying one vector into another takes O(n) time complexity
    v2.push_back(11);
    v2.push_back(12);
    printVect(v2);
    printVect(v);  // original vector v remains same as a copy of v is copied to v2
    */
    
    
    
    /*(2)
    vector<int> v;   // Vectors are like arrays whose size can change dynamically.  (Here,size of vector is zero as it is not initialised)
    int n;
    cout<<"Enter the no. of elements in the vector: ";
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    printVect(v);
    */
    
    
    
    /*(3)
    int n;
    vector<int> v(n);    // Initially n elements are initialised to 0 in the vector v
    
    cout<<"Enter the no. of elements in the vector: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    */

   
    /*(4)
    vector<string> v;    // vector of strings
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    */
    
    return 0;
}