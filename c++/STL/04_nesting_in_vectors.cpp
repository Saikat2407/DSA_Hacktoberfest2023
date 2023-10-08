// (1) Pair               ==>    pair<int,int> p2 = {15,18};                             (pair of integer & integer)
// (2) Vector             ==>    vector<int> v = {4, 5, 6};                              (vector of integers)
// (3) Array of pairs     ==>    pair<int,int> p_arr[3] = {{5,10},{6,12},{7,14}};
// (4) Vector of pairs    ==>    vector<pair<int,int> >  v = {{1,2},{24,36},{62,69}};    (better than (1))
// (5) Array of vectors   ==>    vector<int> v[N];                                       (v is an array of N vectors each of different/same size)
// (6) Vector of vectors  ==>    vector<vector<int> > v;                                 (v is an vector of N vectors each of different/same size)

// Array of vectors is two dimensional array with fixed number of rows where each row is vector of variable length. Each index of array stores a vector which can be traversed and accessed using iterators
// Vector of arrays is not possible:-
// You cannot store arrays in a vector or any other container. The type of the elements to be stored in a container (called the container's value type) must be both copy constructible and assignable. Arrays are neither.

#include <bits/stdc++.h>
using namespace std;

void printVect(vector<pair<int,int> > &v){
    cout<< "Size: "<<v.size()<<endl;
    cout<<"Given vector is "<<endl; 
    for(int i=0; i<v.size(); i++){
       cout<< v[i].first<<" "<<v[i].second<<endl;  // v[i] is a pair, not an integer
    }
    cout<<endl;
}

int main(){
    
    /*(1)
    vector<pair<int,int> >  v = {{1,2},{24,36},{62,69}};    // vector of pairs
    printVect(v);
    */
    
    
    /*(2)
    vector<pair<int,int> >  v;    // vector of pairs
    int n;
    cout<<"Enter the no. of pairs in the vector: ";
    cin>>n;
    cout<<"Enter the elements in each pair of the vector: "<<endl;
    for(int i=0; i<n; i++){
        int x,y;
        cin>> x >> y;
        v.push_back({x,y});  //or  v.push_back(make_pair(x,y));
    }
    printVect(v);
    */

    
    /*(3)
    int N;  
    cin >> N;  // N is the no. of vectors in the array
    
    vector<int> v[N];  // v is an array of N vectors each of different/same size...v[i] is i-th vector of this array v.
    for(int i=0; i<N; i++){
        int n;
        cin >> n;  // n is the size of each vector                    // input:-
        for(int j=0; j<n; j++){                                         // 3         is 3 vectors in the array v
            int x;                                                      // 4
            cin >> x;   // x is the element in each vector              // 7 8 9 10  is v[0] vector
            v[i].push_back(x);                                          // 2
        }                                                               // 30 40     is v[1] vector
    }                                                                   // 3
                                                                        // 14 16 18  is v[2] vector

    for(int i=0; i<N; i++){
        cout<<"Size: "<<v[i].size()<<endl;
        for(int j=0; j<v[i].size(); j++){
            cout<< v[i][j]<<" ";
        }
        cout<<endl;
    }
    */


    /*(4)
    int N;  
    cin >> N;  // N is the no. of vectors in the vector
    
    vector<vector<int> > v;  // v is an vector of N vectors each of different/same size...v[i] is i-th vector of this vector v.
    for(int i=0; i<N; i++){
        int n;                                                          // input:-
        cin >> n;  // n is the size of each vector                      // 3         is 3 vectors in the vector v.
        vector<int> temp;     // (initially vector v is empty)          // 4
        for(int j=0; j<n; j++){                                         // 7 8 9 10  is v[0] vector
            int x;                                                      // 2
            cin >> x;   // x is the element in each vector              // 30 40     is v[1] vector
            temp.push_back(x);                                          // 3
        }                                                               // 14 16 18  is v[2] vector
        v.push_back(temp);  // push each vector temp into vector v.                                                         
    }                                                                   
                                                                        

    for(int i=0; i<N; i++){
        cout<<"Size: "<<v[i].size()<<endl;
        for(int j=0; j<v[i].size(); j++){
            cout<< v[i][j]<<" ";
        }
        cout<<endl;
    }
    */


    return 0;
}