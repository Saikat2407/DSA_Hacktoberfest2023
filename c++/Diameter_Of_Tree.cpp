#include <bits/stdc++.h>
using namespace std;


const int N=2e5+10;
vector<int> g[N];
vector<int> depth(N);
 
void dfs(int v,int par=-1)
{
for(auto child:g[v])
{
    if(child==par) continue;
    depth[child]=depth[v]+1;
    dfs(child,v);
}  
}

 
int main()
{
    // Enter the number of nodes in the tree
    int n;
    cin>>n;
    
    //Enter all the edges in the tree one by one 
    for(auto i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dfs(1);
    int ans=-1,bro;
    for(auto i=1;i<=n;i++)
    {
        if(depth[i]>ans)
        {
            ans=depth[i];
            bro=i;
        }
        depth[i]=0;
    }
    
    dfs(bro);
    
    for(auto i=1;i<=n;i++)
    {
        if(depth[i]>ans)
        {
            ans=depth[i];
        }
    }
    
    cout<<ans<<endl;
 
}

