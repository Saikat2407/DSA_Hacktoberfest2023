// Upper Bound and Lower Bound questions are those of binary search only.
// Lower and upper bounds return memory location (pointers in case of arrays and iterators in case of vectors).
// Lower and upper bounds are always used in 'sorted' array/vector since it works in O(log n) time. Else it will work in O(n) time. (sets & maps are already sorted)

/*  
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
The lower bound of x is the smallest index ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
*/      

/*
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.
The upper bound is the smallest index, ind, where arr[ind] > x.
But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. The main difference between the lower and upper bound is in the condition. 
For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.
*/

// Example : 4 5 5 7 8 25
// for 5, lower bound is 5 at index 1;  for 7, lower bound is 7 at index 3;  for 6, lower bound is 7 at index 3;  for 30, lower bound is end iterator i.e 6.
// for 5, upper bound is 7 at index 3;  for 7, upper bound is 8 at index 4;  for 6, upper bound is 7 at index 3;  for 30, upper bound is end iterator i.e 6.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* (1)
    int n = 6;
    int a[n] = {4,5,5,25,7,8};

    sort(a, a+n); // for sorting n elements, take 0 to (n-1) indices of the array. And arr+n not included while sorting.
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout<<endl;

    int* ptr = lower_bound(a, a+n, 6);    // O(log n)
    if(ptr == a+n){
        cout<<"not found"<<endl;
        return 0;
    }
    cout<<*ptr<<endl;    // 7

    int* ptr2 = upper_bound(a+2, a+n, 7);   // O(log n)
    if(ptr2 == a+n){
        cout<<"not found"<<endl;
        return 0;
    }
    cout<<*ptr2<<endl;   // 8
    */

    //------------------------------------------------------------------------------------------

    /* (2)
    int n = 6;
    vector<int> v = {4,5,5,25,7,8};

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout<<endl;

    auto it = lower_bound(v.begin(), v.end(), 6);    // O(log n)
    if(it == v.end()){
        cout<<"not found"<<endl;
        return 0;
    }
    cout<<*it<<endl;    // 7

    auto it2 = upper_bound(v.begin()+2, v.end(), 7);   // O(log n)
    if(it2 == v.end()){
        cout<<"not found"<<endl;
        return 0;
    }
    cout<<*it2<<endl;   // 8
    */

    //------------------------------------------------------------------------------------------

    /* (3)
    set<int> s({5,4,25,8,7,5});

    // auto it = lower_bound(s.begin(), s.end(), 5);  // O(n)
    auto it = s.lower_bound(5); // O(log n)   --> better way
    if (it == s.end()) {
        cout << "not found" << endl;
        return 0;
    }

    cout << *it << endl;   // 5
    */

    return 0;
}