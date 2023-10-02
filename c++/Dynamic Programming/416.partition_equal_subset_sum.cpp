// QUESTION LINK ---> https://leetcode.com/problems/partition-equal-subset-sum/
//Solved using Memoization
class Solution {
public:
    bool solve(vector<int>& nums, int i,int sum,int &totalSum,vector<vector<int>> &dp){
      //Base Cases
        if(i>=nums.size()) return false;
        if(sum==totalSum-sum) return true;
      
        if(dp[i][sum]!=-1) return dp[i][sum];
        //notPick the curr element
        if(solve(nums,i+1,sum,totalSum,dp)==true) return dp[i][sum] = true;
      
        //pick the curr element
        if(solve(nums,i+1,sum+nums[i],totalSum,dp)==true) return dp[i][sum] = true;

        return dp[i][sum] = false;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto &it : nums) totalSum+=it;
      
        vector<vector<int>> dp(nums.size(),vector<int>(totalSum+1,-1));
        return solve(nums,0,0,totalSum,dp);
    }
};
