#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int n,d1=0,d2=0;
    cin>>n;
    int m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m[i][j];
            if(i==j)
                d1+=m[i][j];
            if((i+j)==(n-1))
                d2+=m[i][j];
        }
        
    }cout<<abs(d1-d2);
    return 0;
}
