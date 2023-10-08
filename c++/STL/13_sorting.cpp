// STL uses Introsort algorithm - a combination of quick sort, heap sort and insertion sort.
// Introsort - worst case and best case both are O(n*logn).

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    /*(1)
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // sort takes pointer(address) of the first element till pointer of the next to last element which needs to be sorted.
    sort(arr, arr + n);   // for sorting 0 to (n-1) indices of the array, parameters will be sort(arr+0 , arr+n)
    for(int i=0; i<n; i++){    // arr itself stores the address of the first element in the array (no need of * or & operator here)
        cout<<arr[i]<<" ";   
    }
    cout<<endl;
    */

    
    
    /*(2)
    int n;
    cin>>n;  // 7
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];           // 4 2 9 7 5 8 6
    }
    
    sort(arr+2, arr + n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";     // 4 2 5 6 7 8 9
    }
    cout<<endl;
    */

    
    
    /*(3)
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    sort(arr, arr + n, greater<int>());    // to sort in descending order, give a third parameter to sort i.e greater<int>().
  
    cout << "Array after sorting in descending order : \n";
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    */


    
    /*(4)
    int n;
    cin>>n;  
    vector<int> v;                // or vector<int> v(n)
    for(int i=0; i<n; i++){
        int x;
        cin>> x;                  // or cin>> v[i]
        v.push_back(x);           
    }
    
    sort(v.begin() + 2, v.end());  // v.end() point to address of next to last element
    for(int i=0; i<n; i++){           //   for (auto x : v)
        cout<<v[i]<<" ";              //        cout << x << " ";
    }     
    cout<<endl;
    */


    return 0;
}