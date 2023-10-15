// Problem Link: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/0 

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int left  = 0;
        int right = n-1;
        int leftmax = 0;
        int rightmax = 0;
        long long res = 0;
        while(left <= right)
        {
            if(arr[left] <= arr[right])
            {
                if(arr[left] >= leftmax)
                {
                    leftmax = arr[left];
                }
                else
                {
                    res += leftmax - arr[left];
                }
                left++;
            }
            else
            {
                if(arr[right] >= rightmax)
                {
                    rightmax = arr[right];
                }
                else
                {
                    res += rightmax - arr[right];
                }
                right--;
            }
        }
        return res;
        //Time Complexity: O(N) because we are using 2 pointer approach.

        //Space Complexity: O(1) because we are not using anything extra.
    }
};