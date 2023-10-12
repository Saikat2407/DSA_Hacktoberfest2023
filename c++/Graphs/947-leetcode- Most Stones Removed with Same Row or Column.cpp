//problem-link->https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        queue<pair<int,int>> q;
        int n = 0;
        for(int i = 0 ; i < stones.size() ; i++){
            n = max(n,stones[i][0]);
            n = max(n,stones[i][1]);
        }
        n++;
        vector<vector<int>> row(n);
        vector<vector<int>> col(n);
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(auto i : stones){
            row[i[0]].push_back(i[1]);
            col[i[1]].push_back(i[0]);
        }
        int comps = 0;
        for(auto i : stones){
            if(vis[i[0]][i[1]] == true) continue;
            q.push({i[0],i[1]});
            vis[i[0]][i[1]] =true;
            while(q.size()){
                int x= q.front().first,y = q.front().second;
                q.pop();
                for(int j : row[x]){
                    if(vis[x][j]) continue;
                    vis[x][j] = true;
                    q.push({x,j});
                }
                for(int j : col[y]){
                    if(vis[j][y]) continue;
                    vis[j][y] = true;
                    q.push({j,y});
                }

            }
                comps++;
        }        
        return stones.size()-comps;
    }
};