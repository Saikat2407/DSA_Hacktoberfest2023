// KMP Algorithm for Pattern Searching 
// Question Name: Last Match
// GeeksForGeeks Link : https://practice.geeksforgeeks.org/problems/last-match1928/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Problem Statement: Given two strings A and B, you need to find the last occurrence ( 1 based indexing) of string B in string A.

// Solution 

#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    void gps(vector<int> &lps,string B){
        int m=B.size();
        int len=0;
        int i=1;
        while(i<m){
            if(B[i]==B[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                   lps[i]=0;
                   i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
    } 
    int findLastOccurence(string A,string B){
        int n=A.size(),m=B.size();
        vector<int> lps(m,0);
        gps(lps,B);
        int i=0,j=0;
        int last=-1;
        while(n-i>=m-j){
            if(j==m){
                last=i-m+1;
                j=lps[j-1];
            }
            else if(A[i]==B[j]){
                i++;
                j++;
            }
            else{
                if(i<n && A[i]!=B[j]){
                    if(j>0) j=lps[j-1];
                    else i++;
                }
            }
        }
        return last;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
string a,b;
cin>>a>>b;
Solution ob;
cout<<ob.findLastOccurence(a,b)<<endl;
    }
    return 0;
}