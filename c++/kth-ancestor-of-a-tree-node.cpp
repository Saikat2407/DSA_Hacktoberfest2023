// Leetcode Problem 1483 Kth Ancestor of a Tree Node
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

// Solution

class TreeAncestor
{
    vector<vector<int>> up;
    int LOG;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        LOG = 0;
        while ((1 << LOG) <= n)
        {
            LOG++;
        }
        up = vector<vector<int>>(n, vector<int>(LOG));
        //setting up first ancestor
        for (int i = 0; i < n; i++)
            up[i][0] = parent[i];

        //setting up other ancestors
        for (int j = 1; j < LOG; j++)
        {
            for (int v = 0; v < n; v++)
            {
                if (up[v][j - 1] == -1)
                    up[v][j] = -1;
                else
                    up[v][j] = up[up[v][j - 1]][j - 1];
            }
        }
    }
    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < LOG; i++)
        {
            if (((1 << i) & k) >= 1)
            {
                node = up[node][i];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};