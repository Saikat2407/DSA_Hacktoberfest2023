/* 
 Que; Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.
 (Kadane Algorithm)
*/
Intuition:
The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray 
with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.


class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxSum = arr[0];
        int currentSum = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            currentSum = max(arr[i], currentSum + arr[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
