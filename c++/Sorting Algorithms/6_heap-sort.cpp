// Heap Sort -->  T.C:  O(N*log(N)) in all cases,  S.C: O(1) ;  where N = size of the array


#include <bits/stdc++.h>
using namespace std;

void heapSort(vector<int> &v){
    int n = v.size();

    
}

int main(){
    vector<int> nums = {13, 46, 24, 52, 50, 9};

    heapSort(nums);

    for (auto i : nums){
        cout << i << " ";
    }

    return 0;
}