//Problem Link: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //tabulation method 
    int matrixMultiplication_t(int N, int arr[])
    {
        int dp[101][101] = {0};
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int ans = 1e9;
                for(int k=i;k<j;k++){
                    int t = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                    if(t<ans) ans = t;
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][N-1];
    }






    int util(int i,int j,int arr[],vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;
        for(int k=i;k<j;k++){
            int t = (arr[i-1] * arr[k] * arr[j]) + util(i,k,arr,dp) + util(k+1,j,arr,dp);
            if(t<ans) ans = t;
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return util(1,N-1,arr,dp);
        
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
