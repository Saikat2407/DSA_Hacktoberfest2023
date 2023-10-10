/*
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

Question link :- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/?envType=daily-question&envId=2023-10-10

*/

/* SOLUTION*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        
        int n = nums.size(); 
        int left = 0;
        int maxCount = 1;
        int currentCount = 1; 

       
        for (int right = 1; right < n; ++right) {
           
            if (nums[right] == nums[right - 1]) {
                continue; 
            }

          
            while (nums[right] - nums[left] > n - 1) {
                
                if(left<n && nums[left+1]==nums[left]){
currentCount++;
}
                left++;
                currentCount--;
            }

         
            currentCount++;

        
            maxCount = max(maxCount, currentCount);
        }

        int minOps = n - maxCount;

        return minOps;
    }
};