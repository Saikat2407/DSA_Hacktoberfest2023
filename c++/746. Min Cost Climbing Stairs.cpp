// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{

    int a = cost[0];
    int b = cost[1];
    int mincost = 0;
    for (int i = 2; i < cost.size(); i++)
    {
        mincost = min(a, b) + cost[i];
        a = b;
        b = mincost;
    }
    return min(a, b);
}

int main()
{
    vector<int> cost(3);
    cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost);
}