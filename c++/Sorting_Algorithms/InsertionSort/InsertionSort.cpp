// insertion sort 

#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)  //taking array 
    {
        cin>>arr[i];
    }
    for(int i=1; i<n; i++)        //insertion sort ....in this we start with 2nd element i.e of index 1
    {                             // current is of index 1 element and j is 0 index element 
        int current= arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){          //compairing both element 
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;                    //upadating current element 
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}