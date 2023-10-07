/*
LeetCode 18 4Sum
Description : 

    Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    - 0 <= a, b, c, d < n
    - a, b, c, and d are distinct.
    - nums[a] + nums[b] + nums[c] + nums[d] == target

    You may return the answer in any order.

Question Link : https://leetcode.com/problems/4Sum/description/

Time: O(N^3)
Space: O(N)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Create a set to store unique quadruplets
        set<vector<int>> result;
        
        // Sort the input array for easier processing
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // Iterate through the array to fix the first two elements
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                // Use two pointers to find the remaining elements
                int left = j + 1;
                int right = n - 1;
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                
                while(left < right) {
                    long long sum = (long long)nums[left] + (long long)nums[right];
                    
                    if(sum == newTarget) {
                        // Found a valid quadruplet, add it to the result set
                        result.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    } else if(sum < newTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        // Convert the set to a vector for the final result
        vector<vector<int>> ans(result.begin(), result.end());
        
        return ans;
    }
};