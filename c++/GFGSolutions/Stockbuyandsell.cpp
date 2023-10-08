// GFG PROBLEM : Stock buy and sell

// LINK TO THE PROBLEM : https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1?page=3&sortBy=submissions

// The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on which you buy and sell the stock so that in between those days for which profit can be generated.
// Note: Since there can be multiple solutions, the driver code will print 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will print the string "No Profit" for a correct solution.




//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> res;
        int buy=0;
        int sell = 0;
        int profit=0;
        for(int i=1;i<n;i++)
        {
            if(A[buy]>A[i])
            buy=i;
            else
            if((A[i]-A[buy])>profit)
            {
                sell=i;
                profit=A[i]-A[buy];
            }
            if (profit > 0 && buy != sell) {
            vector<int> transaction = {buy, sell};
            res.push_back(transaction);
            buy = sell = i;
            profit = 0;
        }
        }
        return res;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends