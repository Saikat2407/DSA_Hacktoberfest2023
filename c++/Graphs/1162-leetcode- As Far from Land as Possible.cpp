//problem-link->https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)q.push({i,j});
            }
        }
        if(q.size()==0 or q.size()==n*n)return -1;
        int level=-1;
        int d[]={0,1,0,-1,0};
        while(!q.empty()){
            int k=q.size();
            level++;
            while(k--){
                auto p=q.front();
                q.pop();
                auto x=p.first;
                auto y=p.second;
                for(int i=0;i<4;i++){
                    int nx=x+d[i];
                    int ny=y+d[i+1];
                    if(nx<0 || ny<0|| nx>=n || ny>=n|| grid[nx][ny]==1)continue;
                    q.push({nx,ny});
                    grid[nx][ny]=1;
                }
            }
        }
        return level;
    }
};