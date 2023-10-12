//problem-link->https://leetcode.com/problems/find-eventual-safe-states/
public:
    bool dfs_cycle(vector<vector<int>>& graph,int node,vector<int>&vis,vector<int>&path_vis,vector<int>&check){
        vis[node]=1;
        path_vis[node]=1;
        check[node]=0;

        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs_cycle(graph,it,vis,path_vis,check)){
                    check[node]=0;
                    return true;
                }
            }
            else if(path_vis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        path_vis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>path_vis(n,0);
        vector<int>check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])dfs_cycle(graph,i,vis,path_vis,check);
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            if(check[i]==1)v.push_back(i);
        }
        return v;
    }
};