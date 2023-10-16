
// Question link : https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
//description of the question ->


// An array arr is a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]
// Output: 1
// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1
// Example 3:

// Input: arr = [0,10,5,2]
// Output: 1
 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int s = 0 ; 
        int e = arr.size()-1; 
        int mid = s + (e-s)/2;

        while( s<=e ){
            if( arr[mid]> arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
                // cout<<mid<<endl;
            }else if (arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]){
                s = mid + 1; 
            }else{
                e =mid;
            }
            mid = s + (e-s)/2;
        } 
        return -1;

    }
};

