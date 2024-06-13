#include<bits/stdc++.h>
//using priority queue
//fails if graph contains negative cycle
using namespace std;
int main()
{
    vector<vector<int>>edges={{0,1,4},{0,2,4},{1,2,2},{2,3,3},{2,4,1},{2,5,6},{3,5,2},{4,5,3}};
    map<int,vector<vector<int>>>adj;
    for(auto x:edges)
    {
        adj[x[1]].push_back({x[0],x[2]});
        adj[x[0]].push_back({x[1],x[2]});
    }
    vector<int>dist(6,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //current_distance,node
    for(int i=0;i<6;i++)
        dist[i]=1e9;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty())
    {
        int node = pq.top().second;
        int currdis = pq.top().first;       
        pq.pop();    
        for(auto it: adj[node])
        {
            int edgewt = it[1];
            int adjnode = it[0];    
            if(currdis + edgewt < dist[adjnode])
            {
                dist[adjnode] = currdis+edgewt;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    for(int i=0;i<6;i++)
        cout<<i<<" "<<dist[i]<<endl;
}
