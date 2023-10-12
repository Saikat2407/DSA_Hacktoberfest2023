//problem-link->https://leetcode.com/problems/time-needed-to-inform-all-employees/
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        int ans=0;
        queue<pair<int,int>>q;
        q.push({headID,0});
        vis[headID]=1;
        while(!q.empty()){
            auto node=q.front().first;
            auto t=q.front().second;
            q.pop();
            ans=max(ans,t);
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,t+informTime[node]});
                }
            }
        }
        return ans;
    }
};