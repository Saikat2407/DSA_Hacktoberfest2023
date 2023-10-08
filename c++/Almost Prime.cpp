//Codeforces Solution for "Almost Prime"
//Link: https://codeforces.com/contest/26/problem/A
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    // {
        
    // }
    int n,count=0,st=0;
    cin>>n;
    vector<bool>v(3000,true);
    vector<int>prime;
    for(int i=2;i<=n;i++)
    {
        if(v[i])
        {
            for(int j=i*2;j<=n;j+=i)
            {
                v[j]=false;
            }
            prime.push_back(i);
        }
    }
    if(n<4) cout<<0<<endl;
    else
    {for(int i=1;i<=n;i++)
    {
        count=0;
        for(int j=0;prime[j]<=i && j<prime.size();j++)
        {
            if(i%prime[j]==0) count++;
        }
        if(count==2) st++;
    }
    cout<<st<<endl;
    }
return 0;
}