// Bubble Sort --> T.C:  O(N^2) and best - O(N) , where N = size of the array
// Best case occurs when given array is already sorted
// Pushes the maximum element to the last by adjacent swapping
// For n elements in array, (n-1) iterations are required

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j+1] < v[j])
                swap(v[j], v[j+1]);
        }
    }

}

void bubbleSort2(vector<int>& v){   // different & better way of writing for-loop
    int n = v.size();
    bool didSwap = false;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i; j++){
            if (v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                didSwap = true;
            }
        }
        
        if(didSwap == false)   // if no swapping happens.
            break;
    }
}

void recursive_bubble_sort(vector<int>& v, int n){     // S.C: O(N) auxiliary stack space, T.C: same as iterative bubble sort.
    if (n == 1)    // Base Case: range == 1.
        return;

    bool didSwap = false;
    
    for (int i = 0; i <= n-2; i++) {
        if (v[i] > v[i+1]){
            swap(v[i], v[i+1]);
            didSwap = true;
        }
    }

    if(didSwap == false)    // if no swapping happens.
        return;

    recursive_bubble_sort(v, n-1);    // Range reduced after recursion:
}


int main(){
    vector<int> nums = {13, 46, 24, 52, 50, 9};

    // bubbleSort(nums);
    
    bubbleSort2(nums);

    // int n = nums.size();
    // recursive_bubble_sort(nums, n);

    for (auto i : nums){
        cout << i << " ";
    }

    return 0;
}