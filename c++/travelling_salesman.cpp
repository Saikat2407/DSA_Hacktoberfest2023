#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int V = 4; // Number of vertices in the graph

int tsp(vector<vector<int>> graph, int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
    {
        if (i != s)
            vertex.push_back(i);
    }

    int minPath = INT_MAX;

    do
    {
        int currentPathWeight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            currentPathWeight += graph[k][vertex[i]];
            k = vertex[i];
        }
        currentPathWeight += graph[k][s]; // Return to the starting vertex

        minPath = min(minPath, currentPathWeight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return minPath;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    int startVertex = 0;

    int minPath = tsp(graph, startVertex);

    cout << "Minimum Cost of TSP: " << minPath << endl;

    return 0;
}
