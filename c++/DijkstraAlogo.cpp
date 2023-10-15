#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define the structure for an edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Define a function to find the shortest path between two nodes using Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<Edge>>& graph, int start, int end) {
    int numNodes = graph.size();
    vector<int> distance(numNodes, INT_MAX);
    vector<int> parent(numNodes, -1);
    vector<bool> visited(numNodes, false);

    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int w = edge.weight;

            if (!visited[v] && distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> shortestPath;
    int current = end;
    while (current != -1) {
        shortestPath.push_back(current);
        current = parent[current];
    }

    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}

int main() {
    // Create a weighted graph represented as an adjacency list
    int numNodes = 6;
    vector<vector<Edge>> graph(numNodes);

    // Add edges to the graph
    graph[0].push_back({1, 5});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 6});
    graph[2].push_back({3, 7});
    graph[2].push_back({4, 4});
    graph[3].push_back({4, 1});
    graph[4].push_back({5, 2});

    int startNode = 0;
    int endNode = 5;

    vector<int> shortestPath = dijkstra(graph, startNode, endNode);

    // Print the shortest path
    cout << "Shortest Path from Node " << startNode << " to Node " << endNode << ": ";
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
