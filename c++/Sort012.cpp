/*Sorting 012*/
#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void sort01(int arr[],int n)
{
    int pivot = 1;
    int j = 0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr,i,j);
            j++;
        }
    }

}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0 ;i < size;++i)
    {
        cin>>arr[i];
    }
    sort01(arr,size);
    cout<<"Sorted Array: "<<endl;
     for(int i=0 ;i < size;i++)
    {
        cout<<arr[i];

    }
cout<<endl;
    return 0;
}