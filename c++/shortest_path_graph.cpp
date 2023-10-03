// This C++ program calculates the shortest path between two nodes in an undirected graph using BFS algorithm.

// Including the necessary C++ standard libraries for input/output and data structures.
#include <bits/stdc++.h>
using namespace std;

// Function to find shortest path in an undirected graph
int findShortestPath(vector<vector<int>>& adjacencyList, int startNode, int endNode, int totalNodes) {
    vector<bool> visited(totalNodes, false);
    vector<int> distances(totalNodes, 0);
    queue<int> bfsQueue;

    // Initialization - start node distance set to 0
    distances[startNode] = 0;
    bfsQueue.push(startNode);
    visited[startNode] = true;

    // BFS traversal loop
    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front();
        bfsQueue.pop();

        // To Explore neighbors
        for (int i = 0; i < adjacencyList[currentNode].size(); ++i) {
            int neighborNode = adjacencyList[currentNode][i];
            if (!visited[neighborNode]) {
                // Updates the distance, enqueue, and mark visited
                distances[neighborNode] = distances[currentNode] + 1;
                bfsQueue.push(neighborNode);
                visited[neighborNode] = true;
            }
        }
    }
    // Returns shortest distance to the end node
    return distances[endNode];
}

// This Function adds an edge to the adjacency list
void addEdge(vector<vector<int>>& adjacencyList, int node1, int node2) {
    adjacencyList[node1].push_back(node2);
    adjacencyList[node2].push_back(node1);
}

// Main function
int main() {
    // Reads number of test cases
    int testCases;
    cin >> testCases;

    // Processes each test case
    while (testCases--) {
        int totalNodes, totalEdges, startNode, endNode;
        cin >> totalNodes >> totalEdges;
        vector<vector<int>> adjacencyList(totalNodes);

        // Reads edges and builds the graph
        while (totalEdges--) {
            int node1, node2;
            cin >> node1 >> node2;
            addEdge(adjacencyList, node1, node2);
        }

        // Reads start and end nodes, then finds and prints shortest path
        cin >> startNode >> endNode;
        cout << findShortestPath(adjacencyList, startNode, endNode, totalNodes) << endl;
    }
    // End of program
    return 0;
}
