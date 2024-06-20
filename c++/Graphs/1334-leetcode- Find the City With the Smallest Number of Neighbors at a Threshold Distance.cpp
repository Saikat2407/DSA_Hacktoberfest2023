//problem-link->https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)dist[i][i]=0;
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e9 && dist[k][j]!=1e9 && dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        int citycount=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=dt)cnt++;
            }
            if(cnt<=citycount){
                citycount=cnt;
                ans=i;
            }
        }
        return ans;
    }
};