// Selection Sort -->  T.C:  worst, best and avg - O(n^2) , S.C: O(1) ; where n = size of the array
// Inplace but not stable.
// Select the minimum element and swap it with the leftmost element.

// For no. of elements in array = n,
// swap at index 0 and min of index (0, n-1)
// swap at index 1 and min of index (1, n-1)
// swap at index 2 and min of index (2, n-1)  ...

// swap at index n-2 and min of index (n-2,n-1)

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &v){
    int n = v.size();

    for (int i = 0; i < n-1; i++) {
        int minIndex = i;  // Index of the minimum element
        for (int j = i+1; j < n; j++) {
            if (v[j] < v[minIndex])
                minIndex = j;
        }
        swap(v[i], v[minIndex]); // Swap the minimum element with the current position
        
        // int temp = v[minIndex];
        // v[minIndex] = v[i];
        // v[i] = temp;
    }
}

int main(){
    vector<int> nums = {13, 46, 24, 52, 50, 9};

    selectionSort(nums);

    for (auto i : nums){
        cout << i << " ";
    }

    return 0;
}