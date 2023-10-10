#include <bits/stdc++.h>
using namespace std;
void solveDFS(unordered_map<int, list<int>> &adj, vector<bool> &visited, int node, stack<int> &s)
{

    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            solveDFS(adj, visited, i, s);
        }
    }

    s.push(node);
}
int main()
{
    //given graph
    vector<pair<int, int>> edges;
    edges.push_back({1, 2});
    edges.push_back({2, 4});
    edges.push_back({4, 5});
    edges.push_back({5, 6});
    edges.push_back({4, 6});
    edges.push_back({1, 3});
    edges.push_back({3, 4});

    //make adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    //make visited to track of all nodes
    vector<bool> visited(6, 0);

    //data structure to store the nodes
    stack<int> s;

    //calling the function
    for (int i = 1; i <= 6; i++)
    {
        if (!visited[i])
        {
            solveDFS(adj, visited, i, s);
        }
    }

    //data structure for answer
    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    //printing the ans
    for (auto i : ans)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}