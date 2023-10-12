//problem-link->https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])dfs(it,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>adj;
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int c=0,tot_edges=connections.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(i,adj,vis);
            }
        }
        int redundant= tot_edges-((n-1)-(c-1));
        return (redundant>=(c-1))? c-1 :-1;
    }
};