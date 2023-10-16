# Maze Problem with Rates in C++

This C++ program demonstrates how to add rates to a maze problem and find the shortest path using the A* algorithm.

## Important Points

- Define the maze size and cell rates:
  - `const int ROWS = 5;` and `const int COLS = 5;` represent the size of the maze.
  - `const int cellRates[ROWS][COLS]` defines rates for each cell in the maze.

- Possible movements:
  - `const int dx[]` and `const int dy[]` represent possible movements (up, down, left, right).

- `Node` structure:
  - `Node` struct represents a cell in the maze and contains `x`, `y`, `cost`, and `heuristic` values.
  - Custom comparison operator (`operator>`) for the priority queue.

- `isValid` function:
  - Checks if a given cell is within the maze boundaries.

- `calculateHeuristic` function:
  - Calculates the heuristic (Manhattan distance) for A* algorithm.

- `findShortestPath` function:
  - Implements A* algorithm with rates considered in the cost calculation.

- Main function:
  - Takes user input for start and destination coordinates.
  - Calls `findShortestPath` and displays the shortest path cost.

## Usage

1. Enter start coordinates (x y).
2. Enter destination coordinates (x y).
3. The program calculates and displays the shortest path cost.

Make sure to adjust the maze size and cell rates according to your specific problem.

# Code
```C++
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Define the maze size (you can adjust this as needed)
const int ROWS = 5;
const int COLS = 5;

// Define cell rates in the maze (adjust as needed)
const int cellRates[ROWS][COLS] = {
    {1, 1, 1, 1, 1},
    {1, 2, 1, 1, 1},
    {1, 1, 3, 1, 1},
    {1, 1, 1, 2, 1},
    {1, 1, 1, 1, 1}
};

// Define possible movements (up, down, left, right)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y, cost, heuristic;

    Node(int _x, int _y, int _cost, int _heuristic)
        : x(_x), y(_y), cost(_cost), heuristic(_heuristic) {}

    // Define comparison operator for priority queue
    bool operator>(const Node& other) const {
        return cost + heuristic > other.cost + other.heuristic;
    }
};

bool isValid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

int calculateHeuristic(int x, int y, int destX, int destY) {
    // Calculate Manhattan distance as heuristic
    return abs(x - destX) + abs(y - destY);
}

int findShortestPath(int startX, int startY, int destX, int destY) {
    vector<vector<int>> cost(ROWS, vector<int>(COLS, INT_MAX));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    cost[startX][startY] = 0;
    pq.emplace(startX, startY, 0, calculateHeuristic(startX, startY, destX, destY));

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int x = curr.x;
        int y = curr.y;
        int currCost = curr.cost;

        if (x == destX && y == destY) {
            return currCost;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY)) {
                int newCost = currCost + cellRates[newX][newY]; // Include the rate in the cost

                if (newCost < cost[newX][newY]) {
                    cost[newX][newY] = newCost;
                    pq.emplace(newX, newY, newCost, calculateHeuristic(newX, newY, destX, destY));
                }
            }
        }
    }

    return -1; // No path found
}

int main() {
    int startX, startY, destX, destY;
    
    cout << "Enter start coordinates (x y): ";
    cin >> startX >> startY;
    
    cout << "Enter destination coordinates (x y): ";
    cin >> destX >> destY;

    if (isValid(startX, startY) && isValid(destX, destY)) {
        int shortestPathCost = findShortestPath(startX, startY, destX, destY);

        if (shortestPathCost != -1) {
            cout << "Shortest path cost: " << shortestPathCost << endl;
        } else {
            cout << "No path found." << endl;
        }
    } else {
        cout << "Invalid coordinates entered." << endl;
    }

    return 0;
}
```
