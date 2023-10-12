#include<iostream>
using namespace std;


int main(){

    int arr[5]={3,5,2,8,4};
    int n=5;
    int i=1;
    int curr=0;
    while(i<n){
      curr=arr[i];
        int j=i-1;
          while(curr<arr[j]&&j>=0){
             arr[j+1]=arr[j];
             j--;
          }
          arr[j+1]=curr;
          i++;
    };

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}