// question link : https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

int f(int i,int prev_i,vector<int> &nums,vector<vector<int>> &dp){
    if(i==nums.size()) return 0;

    if(dp[i][prev_i+1]!=-1) return dp[i][prev_i+1];
    int notTake = f(i+1,prev_i,nums,dp);
    int take = INT_MIN;
    if(prev_i==-1 || nums[i]>nums[prev_i]) take = 1 + f(i+1,i,nums,dp);

    return dp[i][prev_i + 1] = max(take,notTake);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    // using memoization
    // Time Complexity : O(N^2)
    // Space Complexity : O(N^2)


    vector<vector<int>> dp(n,vector<int> (n+1,-1));
    return f(0,-1,nums,dp);
}

int main()
{
    vector<int> arr;

    int n;
    cout<<"Enter the number of elements "<<endl;
    cin>>n;
    cout<<"Now Enter the element"<<endl;
    while(n--){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    long long ans = lengthOfLIS(arr);
    cout<<"length of the Longest common subsequences is : "<<ans<<endl;
    return 0;
}

