#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void build_heap(int arr[], int n){
    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }
}  

void heapSort(int arr[], int n){
    int size = n;

    build_heap(arr,n);

    while(size>1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr,size,1);
    }
}
int main(){
    int n;
    cout<<"Enter the size of the heap : "<<endl;
    cin>>n;

    int arr[n];
    arr[0] = -1;
    cout<<"Enter the value of nodes : "<<endl;
    for(int i=1 ; i<=n; i++){
        cin>>arr[i];
    }

    heapSort(arr,n);
    cout<<"Sorted heap is : "<<endl;

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}