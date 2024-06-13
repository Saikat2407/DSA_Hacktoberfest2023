#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>

typedef std::pair<int, char> NodePair;

std::map<char, int> dijkstra(const std::map<char, std::map<char, int>>& graph, char start) {
    std::map<char, int> distances;
    for (const auto& pair : graph)
        distances[pair.first] = std::numeric_limits<int>::max();
    distances[start] = 0;

    std::priority_queue<NodePair, std::vector<NodePair>, std::greater<NodePair>> priorityQueue;
    priorityQueue.emplace(0, start);

    while (!priorityQueue.empty()) {
        char currentNode = priorityQueue.top().second;
        int currentDistance = priorityQueue.top().first;
        priorityQueue.pop();

        if (currentDistance > distances[currentNode])
            continue;

        for (const auto& [nextNode, weight] : graph.at(currentNode)) {
            int distance = currentDistance + weight;
            if (distance < distances[nextNode]) {
                distances[nextNode] = distance;
                priorityQueue.emplace(distance, nextNode);
            }
        }
    }

    return distances;
}

int main() {
    std::map<char, std::map<char, int>> graph = {
        {'A', {{'B', 1}, {'C', 4}}},
        {'B', {{'A', 1}, {'C', 2}, {'D', 5}}},
        {'C', {{'A', 4}, {'B', 2}, {'D', 1}}},
        {'D', {{'B', 5}, {'C', 1}}}
    };
    char startNode = 'A';

    std::map<char, int> shortestDistances = dijkstra(graph, startNode);

    for (const auto& [node, distance] : shortestDistances) {
        std::cout << "Shortest distance from " << startNode << " to " << node << " is " << distance << std::endl;
    }

    return 0;
}
