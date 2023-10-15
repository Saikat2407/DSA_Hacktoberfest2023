class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // https://leetcode.com/problems/is-graph-bipartite/
        vector<int> vis(graph.size(), -1);
        for (int j = 0; j < graph.size(); j++)
        {
            if (vis[j] != -1)
                continue;
            queue<int> q;
            q.push(j);
            vis[j] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto i : graph[node])
                {
                    if (vis[i] == -1)
                    {
                        vis[i] = 1 - vis[node];
                        q.push(i);
                    }
                    else
                    {
                        if (vis[i] == vis[node])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
