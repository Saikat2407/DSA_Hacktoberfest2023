// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.



// This is kadane algorith which is finding maximum sunarray sum in arrays .
// we taken an initial and maxsum 
//taken a loop and adding it in current sum
//find tracks in maximum sum using max 
//if currentsum is lessathe 0 then return back to 0 
//finally we return maximum sum



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n=nums.size();
       int currSum=0;
       int maximumSum=nums[0];
       for(int i=0;i<n;i++){
           currSum=currSum+nums[i];
         maximumSum=max(maximumSum,currSum);
            if(currSum<0)
                currSum=0;
        }
        return maximumSum;
    }
};