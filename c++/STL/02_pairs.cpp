#include <bits/stdc++.h>
using namespace std;

int main(){ 
    pair<int,string> p;          // pairs can store two data types or two containers
    p = make_pair(5,"Hp_arry");    // pair initialisation
    cout<<p.first<<" "<<p.second<<endl;

    pair<int,int> p2 = {15,18};
    //p2 = {15,18};     // Another way to initialise pairs
    cout<<p2.first<<" "<<p2.second<<endl<<endl;

    pair<int,int> q = p2;  // pair p2 is copied to pair q
    cout<<q.first<<" "<<q.second<<endl;
    q.second = 69;
    cout<<q.second<<endl;
    cout<<p2.second<<endl<<endl;  //p2.second remains unchanged as a copy of p2 is passed into pair q.

    pair<int,int> &r = p2; 
    cout<<r.first<<" "<<r.second<<endl;
    r.second = 92;
    cout<<r.second<<endl;
    cout<<p2.second<<endl<<endl;   // Now reference of p2 is passed into r. SO, p2.second will change if r.second changes
    
    int a[] = {5,6,7};
    int b[] = {10,12,14};
    pair<int,int> p_arr[3] = {{5,10},{6,12},{7,14}};  // Array of pairs [vector of pairs is more convenient]
    // p_arr[0] = {5,10};
    // p_arr[1] = {6,12};
    // p_arr[2] = {7,14};
    swap(p_arr[0], p_arr[2]);   // swaps 1st and 3rd element in each of the pairs    
    for(int i=0; i<3; i++){
        cout<<p_arr[i].first<<" ";
        //cout<<p_arr[i].second<<" ";
    }
    
    return 0;
}