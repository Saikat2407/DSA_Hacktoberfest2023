#include <iostream>
using namespace std;

// void merge(int arr[], int l, int mid, int h){
//     int s=h;
//     int b[s++];
//     int k=l;
//     int i=l;
//     int j=mid+1;

//    while(i<=mid && j<=h){
//             if(arr[i]<=arr[j]){
//                 b[k]=arr[i];
//                 k++;
//                 i++;
//             }
//             else{
//                 b[k]=arr[j];
//                 k++;
//                 j++;
//             }
//         }

//     while(i<=mid){
//         b[k]=arr[i];
//         k++;
//         i++;
//     }

//     while(j<=h){
//         b[k]=arr[j];
//         k++;
//         j++;
//     }

//     for(int p=l; p<=h; p++){
//         arr[p]=b[p];
//     }

// }

// void mergeSot( int arr[], int l, int h){
//     if(l==h){
//         return;
//     }

//     int mid = (l+h)/2;

//     mergeSot(arr,l,mid);
//     mergeSot(arr,mid+1,h);
//     merge(arr,l,mid,h);

// }

void merge(int arr[], int low, int mid, int high)
{

    int size = high + 1;
    int temp[size];
    int left = low;
    int right = mid + 1;
    int help = low;

    while (left <= mid && right <= high)
    {

        if (arr[left] < arr[right])
        {
            temp[help] = arr[left];
            left++;
            help++;
        }
        else
        {
            temp[help] = arr[right];
            right++;
            help++;
        }
    }

    while (left <= mid)
    {
        temp[help] = arr[left];
        help++;
        left++;
    }

    while (right <= high)
    {
        temp[help] = arr[right];
        help++;
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{

    // base case
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    // left side of the array to be divided
    mergeSort(arr, low, mid);

    // right side of the array
    mergeSort(arr, mid + 1, high);

    // now merge the single sorted arrays
    merge(arr, low, mid, high);
}

int main()
{

    int arr[9] = {50, 40, 20, 10, 50, 10, 70, 60, 80};

    mergeSort(arr, 0, 8);

    for (int i = 0; i <= 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}