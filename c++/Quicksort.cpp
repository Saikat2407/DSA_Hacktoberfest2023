// Quick Sort

#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

 void printArray(int arr[],int size)
 {
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
 }

 int partition(int arr[],int low,int high)
 {
    int pivot = arr[low];
    int start= low+1;
    int end = high;
    int temp;
    do{
        while(arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end]> pivot)
        {
            end--;
        } 
        if(start<end)
        {
            temp= arr[start];
            arr[start] = arr[end];
            arr[end]= temp;
        }
    }while(start<end);

    // Swap arr[low] and arr[end]
    temp = arr[low];
    arr[low]= arr[end];
    arr[end]=temp;
    return end;

 }

void quickSort(int arr[],int low,int high)
{
    int partiitionindex;
    if(low<high)
    {
        partiitionindex = partition(arr,low,high);
        quickSort(arr,low,partiitionindex-1);
        quickSort(arr,partiitionindex+1,high);
    }
}


int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int A[n];
    cout<<"Enter "<<n<<" elements:";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    printArray(A,n);
    quickSort(A,0,n-1);
    printArray(A,n);
    return 0;
}