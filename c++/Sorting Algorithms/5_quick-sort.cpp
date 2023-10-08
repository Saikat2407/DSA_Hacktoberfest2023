// Quick Sort -->  T.C:  O(N*log(N)),  S.C: O(1) ;  where N = size of the array
// The worst case complexity will be O(N^2) if we end up choosing the largest or smallest element as the pivot always.

// 1) Pick a pivot and place it in its correct place in the sorted array. 2) Then place smaller elements on left and larger on the right.
// Generally, 1st element is selected as pivot and placed in its correct position, but any element can be the pivot.
/* For step 2, set two pointer - i at the pivot and j at the end of array. Then find the first element from left greater than pivot 
   and first element from right smaller than the pivot, and then swap them. Then i++, j--. Repeat till i<j, place the pivot at that position. 
   This pivot then acts as partition index and now repeat the algorithm for left partition and right partition of the pivot. */

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int low, int high){
    int pivot = v[low];
    int i = low; 
    int j = high;
    
    while(i < j){
        while(v[i] <= pivot && i <= high-1){
            i++;
        }
        
        while(v[j] >= pivot && j >= low+1){
            j--;
        }
        
        if(i < j)
            swap(v[i], v[j]);
    }
    
    swap(v[low], v[j]);  // j is the partition index and v[low] is the pivot 
    return j;   
}

void quickSort(vector<int> &v, int low, int high){
   if(low < high){
       int pIndex = partition(v, low, high);
       quickSort(v, low, pIndex-1);
       quickSort(v, pIndex+1, high);
   }
}

int main(){
    vector<int> nums = {13, 46, 24, 52, 50, 9};
    int n = nums.size();

    quickSort(nums, 0, n-1);

    for (auto i : nums){
        cout << i << " ";
    }

    return 0;
}