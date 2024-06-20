#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // Function to add an edge to the tree
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Function to perform BFS and find the farthest node and its distance
    pair<int, int> bfs(int start) {
        vector<bool> visited(V, false);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;
        int farthestNode = start;
        int maxDistance = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();

            if (distance > maxDistance) {
                maxDistance = distance;
                farthestNode = node;
            }

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push({neighbor, distance + 1});
                    visited[neighbor] = true;
                }
            }
        }

        return {farthestNode, maxDistance};
    }

    // Function to calculate the diameter of the tree
    int treeDiameter() {
        pair<int, int> firstBFS = bfs(0); // Start BFS from any node (e.g., node 0)
        pair<int, int> secondBFS = bfs(firstBFS.first); // Find the farthest node from the first BFS

        return secondBFS.second;
    }
};

int main() {
    // Example usage:
    Graph tree(7); // Create a tree with 7 nodes
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);
    tree.addEdge(5, 6);

    int diameter = tree.treeDiameter();
    cout << "The diameter of the tree is: " << diameter << endl;

    return 0;
}
