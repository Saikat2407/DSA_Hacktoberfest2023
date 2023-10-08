// Knapsack with Duplicate Items
// problem link - https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?page=2&category[]=Dynamic%20Programming&sortBy=submissions

// RECURSION  | MEMOIZATION  |  TABULATION  |  SPACE OPTIMIZED

//RECURSION
class Solution{
public:
    int help(int* val,int* wt,int W,int i)
    {
        //base case
        if(i==0)
        return (W/wt[0])*val[0];
        
        //recursive call
        int a,b;
        a=b=0;
        
        a=help(val,wt,W,i-1);
        if(W>=wt[i])
        b=val[i]+help(val,wt,W-wt[i],i);
        
        return max(a,b);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return help(val,wt,W,N-1);
    }
};
 

//MEMOIZATION
class Solution{
public:
    int help(int* val,int* wt,int W,int i,vector<vector<int>>& memo)
    {
        //base case
        if(i==0)
        return (W/wt[0])*val[0];
        
        //memo check 
        if(memo[i][W]!=-1)
        return memo[i][W];
        
        //recursive call
        int a,b;
        a=b=0;
        
        a=help(val,wt,W,i-1,memo);
        if(W>=wt[i])
        b=val[i]+help(val,wt,W-wt[i],i,memo);
        
        return memo[i][W]=max(a,b);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> memo(N,vector<int>(W+1,-1));
        return help(val,wt,W,N-1,memo);
    }
};
 

//TABULATION
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,0));
        
        for(int i=wt[0];i<=W;i++)
        dp[0][i]=(i/wt[0])*val[0];
        
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int a,b;
                a=b=0;
                
                a=dp[i-1][j];
                if(j>=wt[i])
                b=val[i]+dp[i][j-wt[i]];
                
                dp[i][j]=max(a,b);
            }
        }
        
        return dp[N-1][W];
    }
};
 

//SPACE OPTIMIZED
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> pre(W+1,0);
        
        for(int i=wt[0];i<=W;i++)
        pre[i]=(i/wt[0])*val[0];
        
        for(int i=1;i<N;i++)
        {
            vector<int> curr(W+1,0);
            for(int j=0;j<=W;j++)
            {
                int a,b;
                a=b=0;
                
                a=pre[j];
                if(j>=wt[i])
                b=val[i]+curr[j-wt[i]];
                
                curr[j]=max(a,b);
            }
            pre=curr;
        }
        
        return pre[W];
    }
};