#include<bits/stdc++.h>
using namespace std;

//House Robber 

/*You are a professional robber planning to rob houses along a street. Each house has
a certain amount of money stashed, the only constraint stopping you from robbing each
of them is that adjacent houses have security systems connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum 
amount of money you can rob tonight without alerting the police.
*/

//Recurssive Approach
int helper(int ind,vector<int>&arr)
{
    if(ind>=arr.size())
    {
        return 0;
    }

    int take=arr[ind]+helper(ind+2,arr);
    int nontake=helper(ind+1,arr);

    return max(take,nontake);
}

int rob(vector<int>& nums)
{
    return helper(0,nums);
    
}

//Memoization Approach
int helper(int ind,vector<int>&arr,vector<int>&dp)
{
    if(ind>=arr.size())
    {
        return 0;
    }

    if(dp[ind]!=-1)
    {
        return dp[ind];
    }

    int take=arr[ind]+helper(ind+2,arr,dp);
    int nontake=helper(ind+1,arr,dp);

    return dp[ind]=max(take,nontake);
}

int rob(vector<int>& nums)
{
    vector<int>dp(nums.size(),-1);
    return helper(0,nums,dp);   
}

//Tabulation Method
int rob(vector<int>&nums)
{
    int n=nums.size();
    vector<int>dp(n+2,0);

    for(int i=n-1;i>=0;i--)
    {
        dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
    }
    return dp[0];
}