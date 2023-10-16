//Memoisation DP Code

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int t[1000][1000];
bool func(int*v, int n, int w){
    if(w==0){
		return 1;
	}
	if(n==0){
	    return 0;
	}
	if(t[n][w]!=-1){
		return t[n][w];
	}
	//recursive code
	bool cand1,cand2;
	if(v[n-1]<=w){
		cand1=func(v,n-1,w-v[n-1]);
		cand2=func(v,n-1,w);
		return t[n][w]=cand1|cand2;
	}
	return t[n][w]=func(v,n-1,w);
}
    int equalPartition(int n, int v[])
    {
        memset(t,-1,sizeof(t));
    	
    	int suma=0;
    	for(int i=0;i<n;i++){
    		suma+=v[i];
    	}
    	if(suma%2==1){
    	    //cout<<"In"<<endl;
    		return false;
    	}


    	return func(v,n,suma/2);
        // code here
    }
};

// { Driver Code Starts.

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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends



// Problem Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1 //