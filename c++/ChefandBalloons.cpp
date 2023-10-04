#include <bits/stdc++.h>
using namespace std;

// int min(int a,int b,int c)
// {
//     vector <int> arr = {a,b,c};
//     sort(arr.begin(),arr.end());
//     return arr[0];
    
// }

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while (t--)
	{
	    
	    long long int r,g,b,k;
	    cin>>r>>g>>b;
	    cin>>k;
	    long long int val=0;
	    if(r>=k)
        {
            val+=k-1;
        }
        else
        {
            val+=r;
        }
        
        if(g>=k)
        {
            val+=k-1;
        }
        
        else
        {
            val+=g;
        }
        
        if(b>=k)
        {
            val+=k-1;
        }
        else
        {
            val+=b;
        }
        
        cout<<val+1<<endl;
	    
	}
	return 0;
}
