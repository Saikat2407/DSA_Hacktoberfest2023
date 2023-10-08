// Insertion Sort -->  T.C:  O(N^2) and best - O(N) , where N = size of the array
// Best case occurs when array is already sorted becacue the inner while loop will never run then.
// Take an element and place it in its correct order.

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && v[j-1] > v[j]){
            swap(v[j], v[j-1]);
            j--;
        }
    }
    
}

void recursive_insertion_sort(vector<int> &v, int i, int n) {
    if (i == n) return;   // Base Case: i == n.

    int j = i;
    while(j > 0 && v[j-1] > v[j]){
        swap(v[j], v[j-1]);
        j--;
    }    

    recursive_insertion_sort(v, i+1, n);
}

int main(){
    vector<int> nums = {13, 46, 24, 52, 50, 9};

    // insertionSort(nums);

    int n = nums.size();
    recursive_insertion_sort(nums, 0, n);

    for (auto i : nums){
        cout << i << " ";
    }

    return 0;
}