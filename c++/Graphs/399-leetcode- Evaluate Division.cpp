//problem-link->https://leetcode.com/problems/evaluate-division/
class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>mp;
    double dfs(string u, string v,set<string>vis){
        if(mp.find(u)==mp.end() || mp.find(v)==mp.end())return -1.0;
        if(u==v)return 1.0;
        vis.insert(u);
        for(auto it:mp[u]){
            auto adjnode=it.first;
            auto wt=it.second;
            if(vis.find(adjnode)==vis.end()){
                double ans=dfs(adjnode,v,vis);
                if(ans!=-1)return ans* wt;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        mp.clear();
        for(int i=0;i<equations.size();i++){
            auto u=equations[i][0];
            auto v=equations[i][1];
            mp[u].push_back({v,values[i]});
            mp[v].push_back({u,1/values[i]});
        }
        vector<double>ans;
        set<string>vis;
        for(auto it:queries){
            auto u=it[0];
            auto v=it[1];
            auto val=dfs(u,v,vis);
            ans.push_back(val);
        }
        return ans;
    }
};