// PS link: https://leetcode.com/problems/house-robber-ii/description/
// 213. House Robber II
// PS : You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed.
// All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
// Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.


// SOLUTION 
class Solution {
public:
    int houserobber(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
        return max(houserobber(v1),houserobber(v2));
    }
};
