// Subset Sum Problem
/* 
   Given an array of non-negative integers, and a value sum, 
   determine if there is a subset of the given set with sum equal to given sum.

   problem link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?page=2&category[]=Dynamic%20Programming&sortBy=submissions 
*/

/*---------METHOD 1 - MEMOIZATION -------------*/
bool help(vector<int>& arr,int sum,int i,vector<vector<int>>& memo)
{
    //base case
    if(sum<0)
    return 0;
    
    if(sum==0)
    return 1;
    
    if(i<0)
    {
        if(sum==0)
        return 1;
        else
        return 0;
    }
    
    if(memo[i][sum]!=-1)
    return memo[i][sum];
    
    //recursive calls
    bool a=help(arr,sum,i-1,memo);
    if(a)
    return memo[i][sum]=a;
    
    bool b=help(arr,sum-arr[i],i-1,memo);
    return memo[i][sum] = a or b;
}

bool isSubsetSum(vector<int>arr, int sum)
{
    
    vector<vector<int>> memo(arr.size(),vector<int>(sum+1,-1));
    return help(arr,sum,arr.size()-1,memo);
}



/*----------METHOD 2 - TABULATION----------*/

bool isSubsetSum(vector<int>arr, int sum)
{
    
    vector<vector<int>> dp(arr.size(),vector<int>(sum+1,0));
    for(int i=0;i<arr.size();i++)
    dp[i][0]=1;
    
    for(int i=0;i<arr.size();i++)
    {
        for(int j=1;j<=sum;j++)
        {
            bool a,b,c;
            a=b=c=0;
            
            if(i-1>=0)
            a=dp[i-1][j];
            
            if(i-1>=0 and j-arr[i]>=0)
            b=dp[i-1][j-arr[i]];
            
            if(j==arr[i])
            c=1;
            
            dp[i][j]= (a or b or c);
        }
    }
    
    return dp[arr.size()-1][sum];
}