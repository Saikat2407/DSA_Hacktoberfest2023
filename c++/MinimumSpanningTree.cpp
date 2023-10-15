// GFG problem solution of https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/0 

class Solution
{
	public:
	
	
	int parent[1001]; 
	
	void make(int v)
	{
	    parent[v]=v;
	}
	
	int find(int v)
	{
	    if (parent[v]==v)
	    {
	        return v;
	    }
	    return find(parent[v]);
	}
	
	void Union(int a,int b)
	{
	    a=find(a);
	    b=find(b);
	    
	    if (a!=b)
	    {
	        parent[a]=b;
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        for (int i=0;i<V;i++)
        {
            make(i);
        }
        vector <pair<int,pair<int,int>>> v1;
        for (int i=0;i<V;i++)
        {
            for (auto x : adj[i])
            {
                v1.push_back({x[1],{i,x[0]}});
            }
        }
        sort (v1.begin(),v1.end());
        int ans=0;
        for (int i=0;i<v1.size();i++)
        {
            if (find(v1[i].second.first)==find(v1[i].second.second)){
                continue;
            }
            Union(v1[i].second.first,v1[i].second.second);
            ans+=v1[i].first;
        }
        return ans;
        // code here
    }

};